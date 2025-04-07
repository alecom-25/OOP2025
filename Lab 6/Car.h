//
// Created by Alexia on 02.04.2025.
//

#ifndef CAR_H
#define CAR_H
#include "Weather.h"


class Car {
protected:
    int fuel_capacity;
    int fuel_consumption;
    int speed_rain;
    int speed_sunny;
    int speed_snow;
    int nr_letters;
    char* name;
public:
    virtual int GetFuel_Capacity()=0;
    virtual int GetFuel_Consumption()=0;
    virtual int GetSpeed(Weather weather)=0;
    virtual int GetNr_letters()=0;
    virtual char* GetName()=0;
    virtual ~Car() = default;

};



#endif //CAR_H
