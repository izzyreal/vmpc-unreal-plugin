// Fill out your copyright notice in the Description page of Project Settings.

#include "KnobComponent.h"

void UKnobComponent::setPot(std::weak_ptr<mpc::hardware::Pot> pot) {
	this->pot = pot;
}

void UKnobComponent::SetValue(int v) {
	int diff = v - value;

	rotate(diff * 3);

	pot.lock()->setValue(v);

	this->value = v;
}
