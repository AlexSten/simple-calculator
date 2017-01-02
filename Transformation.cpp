#include "Transformation.h"
#include <iostream>

list<string> Transformation::GetFormula()
{	
	m_Formula.clear();
	m_bIsThereNumber = false;
	getline(cin, m_InputLine);

	for (auto x : m_InputLine)
	{
		PushNumber(x);
		PushMathSymbol(x);

		RecordingNumber(x);
	}
	PushLastNumber();
	return m_Formula;
}

bool Transformation::IsThereNumber(char _x)const
{
	bool result = false;
	if (_x == '0' || _x == '1' || _x == '2' || _x == '3' || _x == '4' || _x == '5' || _x == '6' || _x == '7' || _x == '8' || _x == '9' || _x == '.' || _x == ',')
		result = true;
	return result;
}

bool Transformation::IsThereMathSymbol(char _x)const
{
	bool result = false;
	if (_x == '(' || _x == ')' || _x == '*' || _x == '/' || _x == '+' || _x == '-' || _x == '!')
		result = true;
	return result;
}

void  Transformation::RecordingNumber(char _x)
{
	if (IsThereNumber(_x))
	{
		m_bIsThereNumber = true;
		if (_x == ',')
			_x = '.';
		m_TempNumber.push_back(_x);
	}
}

void Transformation::PushNumber(char _x)
{
	if (m_bIsThereNumber && IsThereMathSymbol(_x))
	{
		m_Formula.push_back(m_TempNumber);
		m_TempNumber = "";
		m_bIsThereNumber = false;
	}
}

void Transformation::PushMathSymbol(char _x)
{
	if (IsThereMathSymbol(_x))
	{
		m_Formula.push_back(string(1, _x));
	}
}

void Transformation::PushLastNumber()
{
	m_Formula.push_back(m_TempNumber);
	m_TempNumber = "";
}