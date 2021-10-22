#include "SumValidator.h"

bool SumValidator::checkValid(int num) const
{
	int total = num;
	int kids = m_baseField[1]->getValidator(8)->getAnswer(8);
	int adults = m_baseField[2]->getValidator(9)->getAnswer(9);

	return (kids + adults == total);
}
