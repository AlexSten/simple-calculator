#ifndef COMPUTER_H
#define COMPUTER_H
#include <list>
#include <string>
using namespace std;

class Computer
{
private:
	void ComputeAllBraces(list<string>&);
	void ComputeAllFactorials(list<string>&);
	void ComputeAllMultiplications(list<string>&);
	void ComputeAllDivisions(list<string>&);
	void EqualMathOperations(list<string>&);
	void ComputeSum(list<std::string>&);
	void ComputeSubtraction(list<string>&);
	unsigned int ComputeFactorial(unsigned int);
	double GetNum(list<string>::iterator);
	list<string>::const_iterator findClosingBracket(const list<string>&);
public:
	double Compute(list<string>);
};

#endif COMPUTER_H