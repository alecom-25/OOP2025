//
// Created by Alexia on 02.04.2025.
//

#include "Seat.h"
#include <iostream>
#include "Car.h"
#include "Weather.h"

using namespace std;

Seat::Seat() {
    fuel_capacity = 120;
    fuel_consumption = 17;
    speed_rain = 75;
    speed_snow = 45;
    speed_sunny = 80;
    nr_letters = 4;
    name = new char[nr_letters];
    const char* p = "Seat";
    for(int i = 0; i < nr_letters; i++) {
        name[i] = p[i];
    }
}

int Seat::GetFuel_Capacity() {
    return fuel_capacity;
}

int Seat::GetFuel_Consumption() {
    return fuel_consumption;
}

int Seat::GetSpeed(Weather weather) {
    if (weather == Weather::Sunny) {
        return speed_sunny;
    }
    if (weather == Weather::Snow) {
        return speed_snow;
    }
    return speed_rain;
}

int Seat::GetNr_letters() {
    return nr_letters;
}

char* Seat::GetName() {
    return name;
}
