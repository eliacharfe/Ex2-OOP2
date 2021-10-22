#include "Form.h"

Form::Form()
	: m_name(""), m_id(0), m_num(0)
{
	m_messageWrongFieldAnswer.push_back("\t  Can't contain digits");
	m_messageWrongFieldAnswer.push_back(" Wrong control digit");
	m_messageWrongFieldAnswer.push_back("\t  Out of range");
	m_messageWrongFieldAnswer.push_back("The date has already passed");
	m_messageWrongFieldAnswer.push_back("\t  Can't be negative");
	m_messageWrongFieldAnswer.push_back("\t  The maximum is 10 rooms");
	m_messageWrongFieldAnswer.push_back("\t  Wrong input");
	m_messageWrongFieldAnswer.push_back("\t  Can't be negative");
	m_messageWrongFieldAnswer.push_back("\t  Wrong input");
	m_messageWrongFieldAnswer.push_back("\t  Wrong input");
	m_answers.resize(10);
}
//--------------------------------------
void Form::addField(BaseField * BfieldPtr)
{
	m_baseField.push_back(BfieldPtr);
	m_strFields.push_back(BfieldPtr->getString(int(m_baseField.size()-1)));
	m_falseStrFields.push_back(BfieldPtr->getString(int(m_baseField.size() - 1)));
}
//-----------------------------------------
void Form::fillForm()
{
	m_valid = true;
	for (auto i = 0; i < m_baseField.size(); i++)
	{
		NoDigitValidator* nameValidator = dynamic_cast<NoDigitValidator*> (m_baseValidator[0]);
		IDValidator* IdValidator = dynamic_cast<IDValidator*> (m_baseValidator[0]);
		switch (i)
		{
		case 0:
			if (!m_falseStrFields[i].empty()) {
			  cout << m_falseStrFields[i] << endl;
			  cin >> m_name;
			  m_answers[i] = m_name;
			  m_valid = false;
		    }
			if (nameValidator->checkName(m_name)) {    
				m_falseStrFields[i].clear();
				m_messageWrongFieldAnswer[i] = "";
			}
			break;

		case 1:
			if (!m_falseStrFields[i].empty()) {
				cout << m_falseStrFields[i] << endl;
				cin >> m_id;
				m_answers[i] = to_string(m_id);
				m_valid = false;
			}
			if (IdValidator->checkID(m_id)) {  
				m_falseStrFields[i].clear();
				m_messageWrongFieldAnswer[i] = "";
			}
			break;
		default:
			if (!m_falseStrFields[i].empty()) {
				cout << m_falseStrFields[i] << endl;
				cin >> m_num;
				m_answers[i] = to_string(m_num);
				m_baseField[i]->getValidator(i)->setAnswer(i, m_num);
				m_baseField[i]->setContent(stoi(m_answers[i]));
				m_valid = false;
			}
			if (m_baseField[i]->getValidator(i)->checkValid(m_num)) {
				m_falseStrFields[i].clear();
				m_messageWrongFieldAnswer[i] = "";
			}
			break;
		}
	}
}
//------------------------
bool Form::validateForm() 
{
	int totalPeople = stoi(m_answers[7]);

	if (!m_baseValidator[0]->checkValid(totalPeople)) { // sum validator	
		m_falseStrFields[7].append(m_baseField[7]->getString(7));
		m_falseStrFields[8].append(m_baseField[8]->getString(8));
		m_falseStrFields[9].append(m_baseField[9]->getString(9));
		return false;
	}
	
	if (!m_baseValidator[1]->checkValid(totalPeople)) { // room validator
		m_falseStrFields[5].append(m_baseField[5]->getString(5));
		m_falseStrFields[6].append(m_baseField[6]->getString(6));
		m_falseStrFields[7].append("How many people will come?");
		m_falseStrFields[8].append("How many children are under the age of 18 ?");
		m_falseStrFields[9].append("How many adults are over the age of 18?");
		return false;
	}

	return m_valid ? true : false;
}
//-------------------------------
void Form::addValidator(BaseValidator * BvalPtr)
{
	m_baseValidator.push_back(BvalPtr);
}
//------------------------------------
ostream& operator << (ostream& io, Form & form)
{
	for (unsigned int i = 0; i < form.getSizeStrVec(); i++)
	{
		 io << "-----------------------------------------------\n"
			<<  form.getStrField(i) << " = " << form.getAnswer(i) << "\t " << form.getMessage(i) << endl
			<< "-----------------------------------------------\n";
	}
	return io;
}
//---------------------------------












/*cout << m_baseField[1]->getString(1) << endl;
	cin >> m_id;

	if (m_baseField[1]->getValidator(1)->checkID(m_id)) {
	}

	m_strFields.push_back(m_baseField[1]->getString(1));
	m_answers.push_back(to_string(m_id));*/


	//if (m_baseField[i]->getValidator(i)->checkID(m_id)) {  