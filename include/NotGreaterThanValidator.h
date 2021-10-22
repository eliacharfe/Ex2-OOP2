#pragma once
#include "Utillities.h"
#include "BaseValidator.h"

template < class T >
class NotGreaterThanValidator : public BaseValidator
{
public:
	NotGreaterThanValidator(const int numRooms) : m_numRooms(numRooms) {}

	bool checkValid(int num) const override { return num <= m_numRooms; }

private:
	int m_numRooms;
};