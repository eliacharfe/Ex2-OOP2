#pragma once
#include "BaseValidator.h"

class IDValidator : public BaseValidator
{
public:
	IDValidator();

	bool checkValid(int num) const override;
	bool checkID(uint32_t id) ;

private:

};