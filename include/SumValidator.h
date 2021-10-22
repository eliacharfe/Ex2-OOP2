#pragma once
#include "BaseField.h"
 
class SumValidator : public BaseValidator
{
public:
	SumValidator(const string str, BaseField * totalPeople, BaseField* kids, BaseField* adults) : m_strField(str)	{
		m_baseField.push_back(totalPeople);
		m_baseField.push_back(kids);
		m_baseField.push_back(adults);
	}

	virtual bool checkValid(int num) const override;

private:
	string  m_strField;
	vector < BaseField* > m_baseField;

};