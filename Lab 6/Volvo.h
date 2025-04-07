//
// Created by Alexia on 02.04.2025.
//

#ifndef VOLVO_H
#define VOLVO_H
#include "Car.h"
#include "Weather.h"

class Volvo : public Car{
    public:
    Volvo();
    char* GetName() override;
    int GetNr_letters() override;
    int GetFuel_Capacity() override;
    int GetFuel_Consumption() override;
    int GetSpeed(Weather weather) override;
};



#endif //VOLVO_H
