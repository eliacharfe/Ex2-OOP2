#pragma once
#include "Utillities.h"
#include "BaseField.h"
#include "BaseValidator.h"
#include "NoDigitValidator.h"
#include "IDValidator.h"
#include "RangeValidator.h"
#include "DateValidator.h"
#include "NonNegativeValidator.h"
#include "NotGreaterThanValidator.h"
#include "SumValidator.h"

template < class T > 
class Field : public  BaseField
{
public:
	Field();
private:
};
//---------------------------------------
template <>
class Field < string > : public BaseField
{
public:
	Field(const string strField) : m_strField(strField), m_baseValidator(nullptr) { }

	void addValidator(BaseValidator* p) { m_baseValidator = p; }

	string getString(const int i) const override { return m_strField; }
	BaseValidator* getValidator(const int i) const  override { return m_baseValidator; }
	int getContent() const override { return m_content; }

private:
	string m_strField;
	BaseValidator* m_baseValidator;
};

//-------------------------------------------
template <>
class Field < uint32_t > : public BaseField
{
public:
	Field(const string strField) : m_strField(strField), m_baseValidator(nullptr) { }

	void addValidator(BaseValidator* p) { m_baseValidator = p; }

	string getString(const int i) const override { return m_strField; }
	BaseValidator* getValidator(const int i) const  override { return m_baseValidator; }
	int getContent() const override { return m_content; }

private:
	string m_strField;
	BaseValidator* m_baseValidator;
};

//------------------------------
template <>
class Field < int > : public BaseField
{
public:
	Field(const string strField)  {
		m_strFields.push_back(strField);
		m_strFields.push_back(strField);
		m_strFields.push_back(strField);
		m_strFields.push_back(strField);
		m_strFields.push_back(strField);
		m_strFields.push_back(strField);
		m_strFields.push_back(strField);
		m_strFields.push_back(strField);
		m_strFields.push_back(strField);
		m_strFields.push_back(strField);
	}

	void addValidator(BaseValidator * ptr)  { 
		m_baseValidator.push_back(ptr); 
	  m_baseValidator.push_back(ptr);
	  m_baseValidator.push_back(ptr);
	  m_baseValidator.push_back(ptr);
	  m_baseValidator.push_back(ptr);
	  m_baseValidator.push_back(ptr);
	  m_baseValidator.push_back(ptr);
	  m_baseValidator.push_back(ptr);
	  m_baseValidator.push_back(ptr);
	  m_baseValidator.push_back(ptr);
	}

	string getString(const int i) const override { return m_strFields[i]; }
	BaseValidator* getValidator(const int i) const {return  m_baseValidator[i]; };
	int getContent() const override { return m_content; }

private:
	vector < string > m_strFields;
	vector <  BaseValidator * > m_baseValidator;

};


//------------------------------












	//void addValidator(RangeValidator <int>* p) { m_rangeValidator = p; };
	//void addValidator(DateValidator <int>* p) { m_dateValidator = p;};
	//void addValidator(NonNegativeValidator <int>* p) { m_nonNegativeValidator = p; };
	//void addValidator(NotGreaterThanValidator <int>* p) { m_notGreaterThanValidator = p; };

	//RangeValidator<int>* getValidator() const { return m_rangeValidator; }
	/*DateValidator<int>* getValidator() const { return m_dateValidator; }
	NonNegativeValidator<int>* getValidator() const { return m_nonNegativeValidator; }
	NotGreaterThanValidator<int>* getValidator() const { return m_notGreaterThanValidator; }*/
//
//RangeValidator<int>* m_rangeValidator;
//DateValidator<int>* m_dateValidator;
//NonNegativeValidator<int>* m_nonNegativeValidator;
//NotGreaterThanValidator<int>* m_notGreaterThanValidator;

	