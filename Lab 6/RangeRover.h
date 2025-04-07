//
// Created by Alexia on 02.04.2025.
//

#ifndef RANGEROVER_H
#define RANGEROVER_H
#include "Car.h"
#include "Weather.h"


class RangeRover : public Car{
public:
    RangeRover();
    char* GetName() override;
    int GetNr_letters() override;
    int GetFuel_Capacity() override;
    int GetFuel_Consumption() override;
    int GetSpeed(Weather weather) override;
};



#endif //RANGEROVER_H
