//
// Created by Alexia on 02.04.2025.
//

#ifndef CIRCUIT_H
#define CIRCUIT_H
#include "Car.h"
#include "Weather.h"

struct RaceResult {
    char* name;
    int nr_letters;
    double time, fuel_needed;
    bool finished;
};

class Circuit {
    int len;
    Weather weather;
    Car** cars;
    int nr_cars;
    RaceResult* races;

public:
    Circuit();
    ~Circuit();
    void SetLenght(int lung);
    void SetWeather(Weather vreme);
    void AddCar(Car* car);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};



#endif //CIRCUIT_H
