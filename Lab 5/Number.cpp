//
// Created by Alexia on 24.03.2025.
//

#include "Number.h"
#include<cmath>
using namespace std;

Number::Number(const char *value, int base) : baza(base){
    int nr=0;
    while (value[nr]!='\0') {
        nr++;
    }
    this->numar = new char[nr+1];
    for (int i = 0; i < nr; i++) {
        this->numar[i] = value[i];
    }
    NrCf = nr;
    printf("ctr 1 apelat \n");
}

Number::Number(const Number &other) : baza(other.baza), NrCf(other.NrCf) {
    char* value = new char[NrCf+1];
    for (int i = 0; i < NrCf; i++) {
        value[i] = other.numar[i];
    }
    this->numar = new char[NrCf+1];
    for (int i = 0; i < NrCf; i++) {
        this->numar[i] = value[i];
    }
    printf("ctr copy apelat \n");
}

Number::Number(Number &&number) noexcept : baza(number.baza), NrCf(number.NrCf) , numar(number.numar) {
    number.numar = nullptr;
    number.baza =0;
    number.NrCf = 0;
    printf("ctr move apelat \n");
}

Number::Number(int valoare) {
    int copy = valoare, nrcf = 0;
    while (copy != 0) {
        copy%= 10;
        nrcf++;
        copy/=10;
    }
    NrCf = nrcf;
    copy = valoare;
    numar = new char[NrCf+1];
    for (int i = 0; i < NrCf; i++) {
        numar[i] = copy%10 + '0';
        copy/=10;
    }
    baza = 10;
}

Number::~Number() {
    delete[] numar;
    printf("destr apelat \n");
}

Number &Number::operator=(const Number &number) {
    if (this != &number) {

        baza = number.baza;
        NrCf = number.NrCf;
        numar = new char[NrCf+1];
        for (int i = 0; i < NrCf; i++) {
            numar[i] = number.numar[i];
        }
    }
    return *this;
}

Number &Number::operator=(Number &&number) noexcept{
    if (this != &number) {

        baza = number.baza;
        NrCf = number.NrCf;
        numar = number.numar;

        number.numar = nullptr;
        number.NrCf = 0;
        number.baza = 0;
    }
    return *this;
}

Number &Number::operator=(int valoare) {
    int copy = valoare, nrcf = 0;
    while (copy != 0) {
        copy%= 10;
        nrcf++;
        copy/=10;
    }
    NrCf = nrcf;
    copy = valoare;
    numar = new char[NrCf+1];
    for (int i = 0; i < NrCf; i++) {
        numar[i] = copy%10 + '0';
        copy/=10;
    }
    baza = 10;
    return *this;
}

Number &Number::operator=(char *value) {
    int nrcf = 0;
    while (value[nrcf] != '\0') {
        nrcf++;
    }
    numar = new char[nrcf+1];
    for (int i = 0; i < nrcf; i++) {
        numar[i] = value[i];
    }
    baza = 10;
    NrCf = nrcf;
    return *this;
}

//-----------------------------------------------------------------------
void Number::SwitchBase(int base) {
    int nrbaza10 = 0, power = 1;
    for (int i = NrCf - 1; i >= 0; i--) {
        nrbaza10 += power * (numar[i] - '0');
        //printf("cf %d este: %d si puterea este %d. cifra adaugata este %d si numarul curent este %d \n", i, numar[i] - '0', power, power*(numar[i]  - '0'), nrbaza10);
        power *= baza;
    }
    printf("nrbaza10 = %d \n", nrbaza10);
    int nrnewbase = 0, nrcfnew=0;
    while (nrbaza10 > 0) {
        nrnewbase = nrnewbase*10 + (nrbaza10 % base);
        nrcfnew++;
        nrbaza10 /= base;
    }
    delete[] numar;
    numar = new char[nrcfnew+1];
    for (int i = 0; i < nrcfnew; i++) {
        numar[i] = nrnewbase %10 + '0';
        nrnewbase /= 10;
    }
    baza = nrnewbase;
    NrCf = nrcfnew;
}

Number &Number::operator+=(const Number &number) {
    return *this = *this + number;
}

Number &Number::operator-=(const Number &number) {
    return *this = *this - number;
}

Number operator+(const Number &number1, const Number &number2) {
    int baza_numar = 0;
    baza_numar = ((number1.baza>number2.baza) ? number1.baza : number2.baza);
    Number copy1(number1);
    Number copy2(number2);

    copy1.SwitchBase(10);
    copy2.SwitchBase(10);

    int n1 = 0, n2 = 0;
    for (int i = copy1.NrCf; i >= 0; i--) {
        n1 = n1 + (copy1.numar[i] - '0') * pow(10, i );
    }
    for (int i = copy2.NrCf; i >= 0; i--) {
        n2 = n2 + (copy2.numar[i] - '0') * pow(10, i );
    }

    int max_NrCf = 0;
    (n1>n2) ? max_NrCf = n1 : max_NrCf = n2;

    int suma = n1 + n2;
    char *suma_char;
    suma_char = new char[max_NrCf+1];
    for (int i = 0; i < max_NrCf; i++) {
        suma_char[i] = suma % 10 + '0';
        suma/=10;
    }

    Number rezultat(suma_char, baza_numar);
    rezultat.SwitchBase(baza_numar);
    return rezultat;
}

Number operator-(const Number &number1, const Number &number2) {
    int baza_numar = 0;
    baza_numar = (number1.baza>number2.baza)? number1.baza : number2.baza;
    Number copy1(number1);
    Number copy2(number2);

    copy1.SwitchBase(10);
    copy2.SwitchBase(10);

    int n1 = 0, n2 = 0;
    for (int i = copy1.NrCf; i >= 0; i--) {
        n1 = n1 - (copy1.numar[i] - '0') * pow(10, i );
    }
    for (int i = copy2.NrCf; i >= 0; i--) {
        n2 = n2 - (copy2.numar[i] - '0') * pow(10, i );
    }

    int max_NrCf = 0;
    (n1>n2) ? max_NrCf = n1 : max_NrCf = n2;
    int diferenta = n1 - n2;

    char *dif_char;
    dif_char = new char[max_NrCf+1];
    for (int i = 0; i < max_NrCf; i++) {
        dif_char[i] = diferenta % 10 + '0';
        diferenta/=10;
    }

    Number rezultat(dif_char, baza_numar);
    rezultat.SwitchBase(baza_numar);
    return rezultat;
}

Number &Number::operator--() {
    for (int i = 0; i < NrCf-1; i++) {
        numar[i] = numar[i+1];
    }
    numar[NrCf-1] = '\0';
    NrCf--;
    return *this;
}

Number &Number::operator--(int number) {
    numar[NrCf-1]= '\0';
    NrCf--;
    return *this;
}

char Number::operator[](int index) {
    if (index >= NrCf) {
        return 0;
    }
    return numar[index];
}

bool Number::operator>(const Number &number) const {
    Number copy1(*this);
    Number copy2(number);

    copy1.SwitchBase(10);
    copy2.SwitchBase(10);

    int n1 = 0, n2 = 0;
    for (int i = 0; i < NrCf; i++) {
        n1+= (copy1.numar[i] - '0') * 10;
    }
    for (int i = 0; i < number.NrCf; i++) {
        n2+=(copy2.numar[i] - '0') * 10;
    }

    if (n1 > n2)
        return true;
    return false;
}

bool Number::operator<(const Number &number) const {
    Number copy1(*this);
    Number copy2(number);

    copy1.SwitchBase(10);
    copy2.SwitchBase(10);

    int n1 = 0, n2 = 0;
    for (int i = 0; i < NrCf; i++) {
        n1+= (copy1.numar[i] - '0') * 10;
    }
    for (int i = 0; i < number.NrCf; i++) {
        n2+=(copy2.numar[i] - '0') * 10;
    }

    if (n1 < n2)
        return true;
    return false;
}

bool Number::operator>=(const Number &number) const {
    Number copy1(*this);
    Number copy2(number);

    copy1.SwitchBase(10);
    copy2.SwitchBase(10);

    int n1 = 0, n2 = 0;
    for (int i = 0; i < NrCf; i++) {
        n1+= (copy1.numar[i] - '0') * 10;
    }
    for (int i = 0; i < number.NrCf; i++) {
        n2+=(copy2.numar[i] - '0') * 10;
    }

    if (n1 >= n2)
        return true;
    return false;
}

bool Number::operator<=(const Number &number) const {
    Number copy1(*this);
    Number copy2(number);

    copy1.SwitchBase(10);
    copy2.SwitchBase(10);

    int n1 = 0, n2 = 0;
    for (int i = 0; i < NrCf; i++) {
        n1+= (copy1.numar[i] - '0') * 10;
    }
    for (int i = 0; i < number.NrCf; i++) {
        n2+=(copy2.numar[i] - '0') * 10;
    }

    if (n1 <= n2)
        return true;
    return false;
}

bool Number::operator==(const Number &number) const {
    Number copy1(*this);
    Number copy2(number);

    copy1.SwitchBase(10);
    copy2.SwitchBase(10);

    int n1 = 0, n2 = 0;
    for (int i = 0; i < NrCf; i++) {
        n1+= (copy1.numar[i] - '0') * 10;
    }
    for (int i = 0; i < number.NrCf; i++) {
        n2+=(copy2.numar[i] - '0') * 10;
    }

    if (n1 == n2)
        return true;
    return false;
}

bool Number::operator!=(const Number &number) const {
    Number copy1(*this);
    Number copy2(number);

    copy1.SwitchBase(10);
    copy2.SwitchBase(10);

    int n1 = 0, n2 = 0;
    for (int i = 0; i < NrCf; i++) {
        n1+= (copy1.numar[i] - '0') * 10;
    }
    for (int i = 0; i < number.NrCf; i++) {
        n2+=(copy2.numar[i] - '0') * 10;
    }

    if (n1 != n2)
        return true;
    return false;
}

void Number::Print() const{
    printf("\n");
    for (int i = 0; i < NrCf; i++) {
        printf("%c", this->numar[i]);
    }
    printf("\n");
}

int Number::GetBase() {
    return NrCf;
}

int Number::GetDigitsCount() {
    return NrCf;
}

/*
int val(char num) {
    if (num >= '0' && num <= '9') {
        return (int) num - '0';
    }
    else if (num >= 'A' && num <= 'Z') {
        return (int) num - 'A' + 10;
    }
    else if (num >= 'a' && num <= 'z') {
        return (int) num - 'a' + 10;
    }
    return 0;
}

char caract(int num) {
    if (num >=0 && num <= 9) {
        return (char) num + '0';
    }
    else if (num >= 10 && num <= 99) {
        return (char) (num - 10) + 'A';
    }

}
*/

