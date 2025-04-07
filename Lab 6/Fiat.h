//
// Created by Alexia on 02.04.2025.
//

#ifndef FIAT_H
#define FIAT_H
#include "Car.h"
#include "Weather.h"


class Fiat : public Car {
public:
    Fiat();
    char* GetName() override;
    int GetNr_letters() override;
    int GetFuel_Capacity() override;
    int GetFuel_Consumption() override;
    int GetSpeed(Weather weather) override;
};



#endif //FIAT_H
