#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;


int calc_suma(char* str) {
	int rezultat = 0;
	while (*str) {
		rezultat = rezultat * 10 + (*str - '0');
		str++;
	}
	return rezultat;
}

int main()
{
	char linii[100];
	int suma = 0;

	FILE* file = fopen("in.txt", "r");
	if (file == nullptr) {
		printf(" eroare\n");
		return 1;
	}

	while (fgets(linii, sizeof(linii), file)) {
		suma += calc_suma(linii);
	}
	fclose(file);
	printf("%d ", suma);
	return 0;
}
