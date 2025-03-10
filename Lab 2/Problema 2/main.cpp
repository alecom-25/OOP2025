#include <iostream>
#include <string>
#include "student.h"
#include "functions.h"

using namespace std;

int main()
{
	student student1, student2;

	student1.SetName("Alexia");
	student1.SetMath(10);
	student1.SetEng(9);
	student1.SetHist(9.5);

	student2.SetName("Matei");
	student2.SetMath(8.5);
	student2.SetEng(10);
	student2.SetHist(9.5);

	cout << student1.GetName() << " are media : " << student1.GetAvr() << endl;
	cout << student2.GetName() << " are media : " << student1.GetAvr() << endl;

	return 0;
}