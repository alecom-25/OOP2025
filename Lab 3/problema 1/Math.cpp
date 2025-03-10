//
// Created by Alexia on 10.03.2025.
//

#include "Math.h"

#include <cstdarg>
#include <stdlib.h>
#include <string.h>
using namespace std;

int Math::Add(int a, int b ) {
    return a + b;
}
int Math::Add(int a, int b, int c) {
    return a + b + c;
}

int Math::Add(double a, double b) {
    return a + b;
}

int Math::Add(double a, double b, double c) {
    return a + b + c;
}

int Math::Mul(int a, int b) {
    return a * b;
}
int Math::Mul(int a, int b, int c) {
    return a * b * c;
}

int Math::Mul(double a, double b) {
    return a * b;
}

int Math::Mul(double a, double b, double c) {
    return a * b * c;
}

int Math::Add(int count, ...) {
    va_list list;
    va_start(list, count);
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += va_arg(list, int);
    }
    va_end(list);
    return sum;
}

char* Math::Add(const char *s1, const char *s2) {
    int lung1 = strlen(s1);
    int lung2 = strlen(s2);
    int lung = lung1 + lung2 + 1;
    char* rezultat = new char[lung];
    strcpy(rezultat, s1);
    strcat(rezultat, s2);
    return rezultat;
}