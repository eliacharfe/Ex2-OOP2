#pragma once
#include "Utillities.h"
#include "Field.h"
#include "SumValidator.h"


class Form 
{
public:
	Form();

	void addField(BaseField* p);
	void fillForm();
	bool validateForm() ;

	void addValidator(BaseValidator * p);

	size_t getSizeStrVec() const { return m_strFields.size();}
	string getStrField(const int i) const { return m_strFields[i]; }
	string getAnswer(const int i)const { return m_answers[i]; }
	string getMessage(const int i)const { return m_messageWrongFieldAnswer[i]; }


private:

	vector < BaseField* > m_baseField;

	vector < BaseValidator* > m_baseValidator;

	string m_name;
	uint32_t m_id;
	int m_num;

	vector < string > m_strFields;
	vector < string > m_answers;

	vector < string > m_falseStrFields;
	vector < string > m_messageWrongFieldAnswer;

	bool m_valid = true;

};
//--------------------------------------------

ostream& operator << (ostream& io, Form& form);

//--------------------------------------------



	//void addField(Field < string > *nameField);
 //   void addField(Field < uint32_t > *idField);
	//void addField(Field < int > *num);

	/*Field < string > *m_nameField;
	Field < uint32_t > *m_idField;
	vector < Field <int> * > m_nums;*/