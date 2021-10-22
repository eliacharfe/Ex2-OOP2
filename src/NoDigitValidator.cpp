#include "NoDigitValidator.h"

NoDigitValidator::NoDigitValidator() { }
//----------------------------------
bool NoDigitValidator::checkName(const string name) const
{
	for (int i = 0; i < name.size(); i++)
		if (isdigit(name[i]))
			return false;
	return true;
}
//----------------------------------------------
bool NoDigitValidator::checkValid(int num) const
{
	string name = to_string(num);

	for (int i = 0; i < name.size(); i++)
		if (isdigit(name[i]))
			return false;
	return true;
}
//----------------------------------------------------
