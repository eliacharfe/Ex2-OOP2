#pragma once
#include "Utillities.h"
#include "Consts.h"

class BaseValidator
{
public:
	BaseValidator() { m_answers.resize(10); };

	virtual bool checkValid(int num) const = 0;

	void setAnswer(const int i, const int num) { m_answers[i] = num; }
	int getAnswer(const int i) { return  m_answers[i]; }

protected:

	vector < int > m_answers;
};
