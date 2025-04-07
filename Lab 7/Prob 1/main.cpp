#include<iostream>
using namespace std;

float operator"" _Kelvin(unsigned long long valoare) {
    return valoare + 273.15;
}

float operator"" _Fahrenheit(unsigned long long value) {
    return value * 1.8 + 32;
}

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    printf("a=%f\n", a);
    printf("b=%f\n", b);
    return 0;
}