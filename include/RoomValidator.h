#pragma once
#include "BaseField.h"

class RoomValidator : public BaseValidator
{
public:
	RoomValidator(const string str, BaseField* pairRooms, BaseField* familyRooms, BaseField* totalPeople) : m_strField(str){
		m_baseField.push_back(pairRooms);
		m_baseField.push_back(familyRooms);
		m_baseField.push_back(totalPeople);
	}

	bool checkValid(int num) const override;

private:
	string  m_strField;
	vector < BaseField* > m_baseField;
};