//
// Created by Alexia on 24.03.2025.
//

#ifndef NUMBER_H
#define NUMBER_H
#include <ostream>


class Number {
    char* numar;
    int baza, NrCf;

public:
    Number(const char * value, int base); // where base is between 2 and 16
    Number(const Number& number); //copy constructor
    Number(Number&& number) noexcept ; //move constructor
    Number(int valoare);
    ~Number();

    Number& operator=(const Number& number); // copy assingment
    Number& operator=(Number&& number) noexcept; //move assingment

    Number& operator=(int valoare);
    Number& operator=(char* value);

    Number& operator+=(const Number& number);
    Number& operator-=(const Number& number);

    friend Number operator+(const Number& number1, const Number& number2);
    friend Number operator-(const Number& number1, const Number& number2);

    Number& operator--(); //elimina prima cifra / bitul cel mai semnificativ
    Number& operator--(int); //elimina prima cifra / bitul cel mai nesemnificativ

    char operator[](int index);

    bool operator>(const Number& number) const;
    bool operator<(const Number& number) const;
    bool operator>=(const Number& number) const;
    bool operator<=(const Number& number) const;
    bool operator==(const Number& number) const;
    bool operator!=(const Number& number) const;


    void SwitchBase(int newBase);
    void Print()const;
    int  GetDigitsCount(); // returns the number of digits for the current number
    int  GetBase(); // returns the current base
};



#endif //NUMBER_H
