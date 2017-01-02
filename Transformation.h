#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H
#include <list>
#include <string>
using namespace std;

class Transformation
{
private:
	list<string> m_Formula;
	string m_InputLine;
	string m_TempNumber;
	bool m_bIsThereNumber = false;
private:
	bool IsThereNumber(char _x)const;
	bool IsThereMathSymbol(char _x)const;

	void RecordingNumber(char _x);

	void PushNumber(char _x);
	void PushMathSymbol(char _x);
	void PushLastNumber();
public:
	list<string> GetFormula();
};

#endif TRANSFORMATION_H