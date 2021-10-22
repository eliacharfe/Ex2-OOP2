#pragma once
#include "BaseValidator.h"

template < class T >
class RangeValidator : public BaseValidator
{
public:
	RangeValidator(const int min, const int max) : m_min(min), m_max(max) {}

	bool checkValid(int num) const override { return (num >= m_min && num <= m_max);	}

private:
	int m_min;
	int m_max;

};
//---------------------------------------------
