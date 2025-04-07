//
// Created by Alexia on 02.04.2025.
//

#include "Volvo.h"
#include <iostream>
#include "Car.h"
#include "Weather.h"

using namespace std;

Volvo::Volvo() {
    fuel_capacity = 100;
    fuel_consumption = 14;
    speed_rain = 70;
    speed_snow = 50;
    speed_sunny = 90;
    nr_letters = 5;
    name = new char[nr_letters];
    const char* p = "Volvo";
    for(int i = 0; i < nr_letters; i++) {
        name[i] = p[i];
    }
}

int Volvo::GetFuel_Capacity() {
    return fuel_capacity;
}

int Volvo::GetFuel_Consumption() {
    return fuel_consumption;
}

int Volvo::GetSpeed(Weather weather) {
    if (weather == Weather::Sunny) {
        return speed_sunny;
    }
    if (weather == Weather::Snow) {
        return speed_snow;
    }
    return speed_rain;
}

int Volvo::GetNr_letters() {
    return nr_letters;
}

char* Volvo::GetName() {
    return name;
}
