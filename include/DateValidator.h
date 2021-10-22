#pragma once
#include "BaseValidator.h"
#include <time.h>

template < class T >
class DateValidator : public BaseValidator
{
public:
	DateValidator() {}
	bool checkValid(int num) const override;

private:
};
//------------------------------------------
template<class T>
inline bool DateValidator<T>::checkValid(int num) const
{
	int year = 0;
    for (int i = 0; i < 4; i++){
	    int digit = num % 10;
		year += int(digit * pow(10, i));
		num /= 10;
	}

	time_t Time = time(NULL);
	struct tm* nowTime = localtime(&Time);
	int currYear = nowTime->tm_year + 1900;
	
	return (year >= currYear);
}
//------------------------------------------
