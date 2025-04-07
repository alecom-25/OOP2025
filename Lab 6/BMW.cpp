//
// Created by Alexia on 02.04.2025.
//

#include "BMW.h"
#include <iostream>
#include "Car.h"
#include "Weather.h"

using namespace std;

BMW::BMW() {
    fuel_capacity = 150;
    fuel_consumption = 11;
    speed_rain = 80;
    speed_snow = 45;
    speed_sunny = 95;
    nr_letters = 3;
    name = new char[nr_letters];
    const char* p = "BMW";
    for(int i = 0; i < nr_letters; i++) {
        name[i] = p[i];
    }
}

int BMW::GetFuel_Capacity() {
    return fuel_capacity;
}

int BMW::GetFuel_Consumption() {
    return fuel_consumption;
}

int BMW::GetSpeed(Weather weather) {
    if (weather == Weather::Sunny) {
        return speed_sunny;
    }
    if (weather == Weather::Snow) {
        return speed_snow;
    }
    return speed_rain;
}

int BMW::GetNr_letters() {
    return nr_letters;
}

char* BMW::GetName() {
    return name;
}

