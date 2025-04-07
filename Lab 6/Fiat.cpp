

//
// Created by Alexia on 02.04.2025.
//

#include "Fiat.h"
#include <iostream>
#include "Car.h"
#include "Weather.h"

using namespace std;

Fiat::Fiat() {
    fuel_capacity = 95;
    fuel_consumption = 15;
    speed_rain = 75;
    speed_snow = 55;
    speed_sunny = 95;
    nr_letters = 4;
    name = new char[nr_letters];
    const char* p = "Fiat";
    for(int i = 0; i < nr_letters; i++) {
        name[i] = p[i];
    }
}

int Fiat::GetFuel_Capacity() {
    return fuel_capacity;
}

int Fiat::GetFuel_Consumption() {
    return fuel_consumption;
}

int Fiat::GetSpeed(Weather weather) {
    if (weather == Weather::Sunny) {
        return speed_sunny;
    }
    if (weather == Weather::Snow) {
        return speed_snow;
    }
    return speed_rain;
}

int Fiat::GetNr_letters() {
    return nr_letters;
}

char* Fiat::GetName() {
    return name;
}

