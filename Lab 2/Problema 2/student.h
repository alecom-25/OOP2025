#pragma once
#include <string>
using namespace std;

class student
{
	string nume;
	float math=0, eng=0, hist=0, avr=0;
public:
	void SetName(string name);
	string GetName();
	void SetMath(float numar);
	float GetMath();
	void SetEng(float numar);
	float GetEng();
	void SetHist(float numar);
	float GetHist();
	float GetAvr();

};

