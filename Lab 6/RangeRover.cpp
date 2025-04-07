//
// Created by Alexia on 02.04.2025.
//

#include "RangeRover.h"
#include <iostream>
#include "Car.h"
#include "Weather.h"

using namespace std;

RangeRover::RangeRover() {
    fuel_capacity = 80;
    fuel_consumption = 15;
    speed_rain = 70;
    speed_snow = 50;
    speed_sunny = 80;
    nr_letters = 10;
    name = new char[nr_letters];
    const char* p = "RangeRover";
    for(int i = 0; i < nr_letters; i++) {
        name[i] = p[i];
    }
}

int RangeRover::GetFuel_Capacity() {
    return fuel_capacity;
}

int RangeRover::GetFuel_Consumption() {
    return fuel_consumption;
}

int RangeRover::GetSpeed(Weather weather) {
    if (weather == Weather::Sunny) {
        return speed_sunny;
    }
    if (weather == Weather::Snow) {
        return speed_snow;
    }
    return speed_rain;
}

int RangeRover::GetNr_letters() {
    return nr_letters;
}

char* RangeRover::GetName() {
    return name;
}
