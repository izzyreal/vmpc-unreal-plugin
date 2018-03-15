#include "RotatingComponent.h"

#include "Runtime/Engine/Classes/PhysicsEngine/BodySetup.h"
#include "Kismet/KismetMathLibrary.h"

#include <hardware/Hardware.hpp>
#include <hardware/Button.hpp>

void URotatingComponent::setPivot(UStaticMeshComponent* pivot) {
	// Pivot is a box mesh located such that when UE does a pivot->Bounds.Origin,
	// the result is an arbitrary point located on the jog wheel's Y-axis.
	this->pivot = pivot;
	GetBodySetup()->CollisionTraceFlag = ECollisionTraceFlag::CTF_UseComplexAsSimple;
}

void URotatingComponent::BeginPlay()
{
	auto actor = GetAttachmentRootActor();
	auto actorRotation = actor->GetActorRotation();
	FRotator zero(0);
	actor->SetActorRotation(zero);

	auto defaultLocation = GetComponentLocation();
	auto defaultRotation = GetComponentRotation();
	auto bodyTiltAngle = 5.11989;
	auto cancelBodyTiltAxis = FVector(1.0f, 0, 0);
	auto axisToRotateAround = FVector(0, 0, 1.0f);
	auto pointToRotateAround = pivot->Bounds.Origin;

	for (int i = 0; i < 360; i++) {
		rotateAroundPoint(this, bodyTiltAngle, pointToRotateAround, cancelBodyTiltAxis, false);
		rotateAroundPoint(this, i, pointToRotateAround, axisToRotateAround, false);
		rotateAroundPoint(this, -bodyTiltAngle, pointToRotateAround, cancelBodyTiltAxis, true);
		SetWorldLocationAndRotation(defaultLocation, defaultRotation);
	}
	actor->SetActorRotation(actorRotation);
}

void URotatingComponent::rotate(int degrees) {
	degreesToRotate += degrees;
}

void URotatingComponent::checkRotation() {
	if (degreesToRotate > 0) {
		rotateOneDegree(true);
	}
	else if (degreesToRotate < 0) {
		rotateOneDegree(false);
	}
}

void URotatingComponent::rotateOneDegree(bool up) {
	int newAngle = currentAngle + (up ? 1 : -1);
	if (newAngle > 359) newAngle -= 360;
	if (newAngle < 0) newAngle += 360;
	auto actor = GetAttachmentRootActor();
	auto actorRotation = actor->GetActorRotation();
	FRotator zero(0);
	actor->SetActorRotation(zero);

	SetWorldLocationAndRotation(newLocations[newAngle], newRotations[newAngle]);

	actor->SetActorRotation(actorRotation);

	currentAngle = newAngle;
	degreesToRotate += (up ? -1 : 1);
}

void URotatingComponent::rotateAroundPoint(UStaticMeshComponent* comp, float angle, FVector pointToRotAround, FVector axisToRotAround, bool store) {
	auto rotatorA = comp->GetComponentRotation();
	auto rotatorB = UKismetMathLibrary::RotatorFromAxisAndAngle(axisToRotAround, angle);
	auto newRot = UKismetMathLibrary::ComposeRotators(rotatorA, rotatorB);
	auto actorLoc = comp->GetComponentLocation();
	auto vecToRotateAroundAxis = actorLoc - pointToRotAround;
	auto rotatedVec = UKismetMathLibrary::RotateAngleAxis(vecToRotateAroundAxis, angle, axisToRotAround);
	auto newLoc = rotatedVec + pointToRotAround;
	comp->SetWorldLocationAndRotation(newLoc, newRot);
	if (store) {
		newLocations.push_back(newLoc);
		newRotations.push_back(newRot);
	}
}

URotatingComponent::~URotatingComponent() {
}
