#pragma once
#include "Utillities.h"
#include "Consts.h"
#include "BaseValidator.h"

class BaseField
{
public:
	BaseField() : m_content(0) {}

	virtual string getString(const int i) const = 0;
	virtual BaseValidator* getValidator(const int i) const = 0;

	void setContent(int content) { m_content = content; };
	virtual int getContent() const = 0;

protected:
	int m_content;
};