#include<iostream>
#include<string.h>
#include<cstdio>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(suppress : 4996)
using namespace std;
int main()
{
	char sir[100], *p, cuvinte[100][100];
	int nr = 0, i, j;
	char* context = nullptr;
	//cin.get(sir, 255);
	scanf("%[^\n]", sir);
	p = strtok(sir, " ");
	while (p)
	{
		strcpy(cuvinte[nr], p);
		nr++;
		p = strtok(NULL, " ");
	}
	for (i = 0; i < nr - 1; i++)
		for (j = i + 1; j < nr; j++)
			if (strlen(cuvinte[i]) < strlen(cuvinte[j]))
				swap(cuvinte[i], cuvinte[j]);
			else
				if (strlen(cuvinte[i]) == strlen(cuvinte[j]))
					if (strcmp(cuvinte[i], cuvinte[j]) > 0)
						swap(cuvinte[i], cuvinte[j]);
	for (i = 0; i < nr; i++)
		//cout << cuvinte[i] << endl;
		printf("%s \n", cuvinte[i]);
	return 0;
}