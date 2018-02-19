#pragma once
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include <observer/Observer.hpp>

class DataWheelObserver : public moduru::observer::Observer {

private:
	int dataWheelIndex = 0;
	UStaticMeshComponent* DataWheel;

public:
	void update(moduru::observer::Observable* o, boost::any arg) override;

public:
	DataWheelObserver(UStaticMeshComponent* DataWheel);

};