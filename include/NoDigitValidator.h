#pragma once
#include "BaseValidator.h"

class NoDigitValidator : public BaseValidator
{
public:
	NoDigitValidator();

	bool checkName(const string name) const;
	bool checkValid(int num) const override;

private:

};