//
// Created by Alexia on 02.04.2025.
//

#ifndef BMW_H
#define BMW_H
#include "Car.h"
#include "Weather.h"

class BMW : public Car {
    public:
        BMW();
        char* GetName() override;
        int GetNr_letters() override;
        int GetFuel_Capacity() override;
        int GetFuel_Consumption() override;
        int GetSpeed(Weather weather) override;
};



#endif //BMW_H
