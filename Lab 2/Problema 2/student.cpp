#include "student.h"

using namespace std;

void student::SetName(string name)
{
	nume = name;
}

string student::GetName()
{
	return nume;
}

void student::SetMath(float numar)
{
	if (numar >= 1 && numar <= 10)
		math = numar;
}

float student::GetMath()
{
	return math;
}

void student::SetEng(float numar)
{
	if (numar >= 1 && numar <= 10)
		eng = numar;
}

float student::GetEng()
{
	return eng;
}

void student::SetHist(float numar)
{
	if (numar >= 1 && numar <= 10)
		hist = numar;
}

float student::GetHist()
{
	return hist;
}

float student::GetAvr()
{
	return (math + eng + hist) / 3.;
}
