#include "Computer.h"
#include <algorithm>


double Computer::Compute(list<string> _listStr)
{
	ComputeAllBraces(_listStr); 
	ComputeAllFactorials(_listStr);
	ComputeAllMultiplications(_listStr);
	ComputeAllDivisions(_listStr);
	EqualMathOperations(_listStr); // + and -
	
	return stod(*_listStr.cbegin());
}

void Computer::ComputeAllBraces(list<string>& _listStr)
{
	auto openningBracket = find(_listStr.begin(), _listStr.end(), "(");
	while (openningBracket != _listStr.end())
	{
		auto closingBracket = findClosingBracket(_listStr);
		
		list<string> newListStr;
		newListStr.splice(newListStr.cbegin(), _listStr, (++openningBracket)--, closingBracket);


		double result = Compute(newListStr);

		_listStr.insert(openningBracket, to_string(result));

		_listStr.erase(openningBracket);
		_listStr.erase(closingBracket);

		openningBracket = find(_listStr.begin(), _listStr.end(), "(");
	}
	auto closingBracket = find(_listStr.begin(), _listStr.end(), ")");
	if (closingBracket != _listStr.end())
		throw "There is mismatching of brackets. Too many closing ones";
}

void Computer::ComputeAllFactorials(list<string>& _listStr)
{
	auto factorial = find(_listStr.begin(), _listStr.end(), "!");
	while (factorial != _listStr.end())
	{
		auto numb = factorial;
		*factorial = to_string(ComputeFactorial(GetNum(++numb)));
		_listStr.erase(numb);

		factorial = find(_listStr.begin(), _listStr.end(), "!");
	}
}

void Computer::ComputeAllMultiplications(list<string>& _listStr)
{
	auto multiple = find(_listStr.begin(), _listStr.end(), "*");
	while (multiple != _listStr.end())
	{
		auto fr = multiple;
		auto sc = multiple;
		*multiple = to_string(GetNum(--fr) * GetNum(++sc));
		_listStr.erase(fr);
		_listStr.erase(sc);

		multiple = find(_listStr.begin(), _listStr.end(), "*");
	}
}

void Computer::ComputeAllDivisions(list<string>& _listStr)
{
	auto division = find(_listStr.begin(), _listStr.end(), "/");
	while (division != _listStr.end())
	{

		auto fr = division;
		auto sc = division;
		if (stod(*(++sc)) == 0) { throw "You can't divide by zero"; }
		*division = to_string(GetNum(--fr) / GetNum(sc));
		_listStr.erase(fr);
		_listStr.erase(sc);

		division = find(_listStr.begin(), _listStr.end(), "/");
	}
}

void Computer::EqualMathOperations(list<string>& _listStr)  // + and -
{
	auto mathOper = find_if(_listStr.begin(), _listStr.end(), [](string elem)->bool {return ((elem == "+") || (elem == "-")); });
	while (mathOper != _listStr.end())
	{
		if (*mathOper == "+")
			ComputeSum(_listStr);
		else if (*mathOper == "-")
			ComputeSubtraction(_listStr);
		mathOper = find_if(_listStr.begin(), _listStr.end(), [](string elem)->bool {return ((elem == "+") || (elem == "-")); });
	}
}

void Computer::ComputeSum(list<string>& _listStr)
{
	auto sum = find(_listStr.begin(), _listStr.end(), "+");

	auto fr = sum;
	auto sc = sum;
	*sum = to_string(GetNum(--fr) + GetNum(++sc));
	_listStr.erase(fr);
	_listStr.erase(sc);
}

void Computer::ComputeSubtraction(list<string>& _listStr)
{
	auto subtraction = find(_listStr.begin(), _listStr.end(), "-");

	auto fr = subtraction;
	auto sc = subtraction;
	*subtraction = to_string(GetNum(--fr) - GetNum(++sc));
	_listStr.erase(fr);
	_listStr.erase(sc);
}

unsigned int Computer::ComputeFactorial(unsigned int _num)
{
	unsigned int result = (_num >0)?(_num*ComputeFactorial(_num - 1)):(1);
	return result;
}

double Computer::GetNum(list<string>::iterator _str)
{
	return (stod(*_str));
}

list<string>::const_iterator Computer::findClosingBracket(const list<string>& _listStr)
{
	int countOfOpenBraces = 0;

	for (auto iterator = _listStr.begin(); iterator != _listStr.end(); ++iterator)
	{
		string str = (*iterator).c_str();
		if (str == "(")
			++countOfOpenBraces;
		if (str == ")")
		{
			--countOfOpenBraces;
			if (countOfOpenBraces == 0)
				return iterator;
		}
	}
	throw "There is mismatching of brackets. Too many openning ones";
}