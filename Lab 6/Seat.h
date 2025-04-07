//
// Created by Alexia on 02.04.2025.
//

#ifndef SEAT_H
#define SEAT_H
#include "Car.h"
#include "Weather.h"


class Seat : public Car {
public:
    Seat();
    char* GetName() override;
    int GetNr_letters() override;
    int GetFuel_Capacity() override;
    int GetFuel_Consumption() override;
    int GetSpeed(Weather weather) override;
};



#endif //SEAT_H
