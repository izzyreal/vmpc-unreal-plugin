#include <control/EnumControl.hpp>

#include <string>

using namespace std;
using namespace ctoot::control;

EnumControl::EnumControl(int id, string name, boost::any value) : Control(id, name)
{
	this->value = value;
}

void EnumControl::setValue(boost::any value)
{
	if (!isEnabled()) return;

	if (!isValueSupported(value)) {
		MLOG("EnumControl::setValue(), requested value is not supported.");
		return;
	}

	// Verify that this comparison does what it should do.
	if (value.type() == this->value.type()) {
		if (string(value.type().name()).find("int") != string::npos) {
			int i1 = boost::any_cast<int>(value);
			int i2 = boost::any_cast<int>(this->value);
			if (i1 != i2) {
				this->value = value;
				notifyParent(this);
			}
		}
		else {
			try {
				string s1 = boost::any_cast<string>(value);
				string s2 = boost::any_cast<string>(this->value);
				if (s1.compare(s2) != 0) {
					this->value = value;
					notifyParent(this);
				}
			}
			catch (const boost::bad_any_cast const &e) {
				string msg = e.what();
				MLOG("EnumControl setValue error, msg: " + msg);
			}
		}
	}
}

boost::any EnumControl::getValue()
{
    return value;
}

bool EnumControl::isValueSupported(boost::any value)
{
	try {
		for (int i = 0; i < getValues().size(); i++) {
			if (value.type() == this->value.type()) {
				if (string(value.type().name()).find("int") != string::npos) {
					int i1 = boost::any_cast<int>(value);
					int i2 = boost::any_cast<int>(this->value);
					if (i1 == i2) {
						return true;
					}
				}
				else {
					string s1 = boost::any_cast<string>(value);
					string s2 = boost::any_cast<string>(this->value);
					if (s1.compare(s2) == 0) {
						return true;
					}
				}
			}
		}
	}
	catch (const boost::bad_any_cast const &e) {
		string msg = e.what();
		MLOG("EnumControl value not supported, error msg: " + msg);
	}
	return false;
}

string EnumControl::toString()
{
	string res = getName().append(" with current value: ").append("getValue()");
	return res;
}

string EnumControl::getValueString()
{
	try {
		int i = boost::any_cast<int>(getValue());
		return to_string(i);
	}
	catch (boost::bad_any_cast& e) {
		try {
			string s = boost::any_cast<string>(getValue());
			return s;
		}
		catch (boost::bad_any_cast& e) {
		}
	}
	return nullptr;
}

void EnumControl::setIntValue(int value)
{
    try {
		setValue(getValues()[value]);
    } catch (const exception& e) {
		printf(e.what());
    }
}

int EnumControl::getIntValue()
{
/*
	int index;
	for (index = 0; index < getValues().size(); index++) {
		if (getValue() == getValues()[index]) return index;
	}
 */
	return -1;
}

int EnumControl::getWidthLimit()
{
    return 40;
}

bool EnumControl::hasLabel()
{
    return false;
}