#include "DataWheelObserver.h"

DataWheelObserver::DataWheelObserver(UStaticMeshComponent* DataWheel) {
	this->DataWheel = DataWheel;
}

static inline void clampIndex(int& dataWheelIndex) {
	if (dataWheelIndex < 0) {
		while (dataWheelIndex < 0)
			dataWheelIndex += 100;
	}
	else if (dataWheelIndex > 99) {
		while (dataWheelIndex > 99)
			dataWheelIndex -= 100;
	}
}

void DataWheelObserver::update(moduru::observer::Observable* o, boost::any arg) {
	int increment = boost::any_cast<int>(arg);
	dataWheelIndex += increment;
	clampIndex(dataWheelIndex);
	// rotate datawheel
	//DataWheel->SetPosition((float) ((dataWheelIndex) / 100.0) * 4.125);
}
