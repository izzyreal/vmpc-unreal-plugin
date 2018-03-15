#pragma once
#include "CoreMinimal.h"
#include <observer/Observer.hpp>

class URotatingComponent;

class DataWheelObserver 
	: public moduru::observer::Observer
{

private:
	URotatingComponent* DataWheel;

public:
	void update(moduru::observer::Observable* o, boost::any arg) override;

public:
	DataWheelObserver(URotatingComponent* DataWheel);
};