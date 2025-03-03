#include<iostream>
#include "NumberList.h"
using namespace std;
int main()
{
	NumberList lista;
	lista.Init();

	lista.Add(24);
	lista.Add(33);
	lista.Add(27);
	lista.Add(14);
	lista.Add(50);
	lista.Sort();
	lista.Print();
	return 0;

}