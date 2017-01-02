#include <iostream>
#include "Computer.h"
#include "Transformation.h"


int main()
{
	Computer CR;
	Transformation TR;
	while (true)
	{
		try
		{
			cout << CR.Compute(TR.GetFormula()) << endl;
		}
		catch (char* exp)
		{
			cout << exp;
			system("pause");
		}
		catch (...)
		{
			cout << "Something went wrong.";
		}
	}
	
	return 0;
}