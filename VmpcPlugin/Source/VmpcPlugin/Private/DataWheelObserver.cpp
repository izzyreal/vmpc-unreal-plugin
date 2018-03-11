#include "DataWheelObserver.h"
#include "RotatingComponent.h"

DataWheelObserver::DataWheelObserver(URotatingComponent* DataWheel) {
	this->DataWheel = DataWheel;
}

void DataWheelObserver::update(moduru::observer::Observable* o, boost::any arg) {
	int increment = boost::any_cast<int>(arg);
	DataWheel->rotate(increment * 3);
}
