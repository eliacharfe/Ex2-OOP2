#include "IDValidator.h"

IDValidator::IDValidator()
{
}
//------------------------------------------
bool IDValidator::checkValid(int num) const
{
	return false;
}
//--------------------------------------------------
bool IDValidator::checkID(uint32_t id) 
{
	string str = to_string(id);
		if (str.size() != 9)
			return false;
	
		int checkDigit = id % 10; // save the check digit for later
		int sum = 0, mul = 1;
	
		for (int i = 0; i < MAX_DIGIT; i++) {
			id /= 10;
			mul = (i % 2 == 0) ? 2 : 1;
			int num = (id % 10) * (mul);
			sum += (num <= 9) ? num : (num % 10 + num / 10);
		}
	
		return ((sum + checkDigit) % 10 == 0);
}
//--------------------------------------------
