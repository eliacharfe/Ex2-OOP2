#pragma once
#include "BaseValidator.h"

template < class T>
class NonNegativeValidator : public BaseValidator
{
public:
	NonNegativeValidator() {}
	bool checkValid(int num) const override { return (num >= 0); }

private:
	
};