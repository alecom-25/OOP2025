#include "functions.h"
#include <cstring>

using namespace std;

int CompName(student& s1, student& s2)
{
	if (strcmp(s1.GetName().c_str(), s2.GetName().c_str()) > 0)
		return 1;
	if (strcmp(s1.GetName().c_str(), s2.GetName().c_str()) == 0)
		return 0;
	return -1;
	
}

int CompMath(student& s1, student& s2)
{
	if (s1.GetMath() > s2.GetMath())
		return 1;
	if (s1.GetMath() == s2.GetMath())
		return 0;
	return -1;
}


int CompEng(student& s1, student& s2)
{
	if (s1.GetEng() > s2.GetEng())
		return 1;
	if (s1.GetEng() == s2.GetEng())
		return 0;
	return -1;
}

int CompHist(student& s1, student& s2)
{
	if (s1.GetHist() > s2.GetHist())
		return 1;
	if (s1.GetHist() == s2.GetHist())
		return 0;
	return -1;
}

int CompAvr(student& s1, student& s2)
{
	if (s1.GetAvr() > s2.GetAvr())
		return 1;
	if (s1.GetAvr() == s2.GetAvr())
		return 0;
	return -1;
}


