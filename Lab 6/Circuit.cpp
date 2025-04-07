#include "Circuit.h"

#include <cstdio>

#include "RangeRover.h"
#include "Car.h"

using namespace std;

Circuit::Circuit(): len(0), weather(Sunny), cars(nullptr), nr_cars(0), races(nullptr) {}

Circuit::~Circuit() {
    delete[] cars;
    delete[] races;
}

void Circuit::SetLenght(int lung) {
    len = lung;
}

void Circuit::SetWeather(Weather vreme) {
    weather = vreme;
}

void Circuit::AddCar(Car *car) {
    Car** new_cars = new Car*[nr_cars + 1];
    for (int i = 0; i < nr_cars; i++) {
        new_cars[i] = cars[i];
    }
    new_cars[nr_cars] = car;
    delete[] cars;
    cars = new_cars;
    nr_cars++;
}

void Circuit::Race() {
    if (races != nullptr) {
        for (int i = 0; i < nr_cars; i++) {
            delete[] races[i].name;
        }
        delete[] races;
    }

    races = new RaceResult[nr_cars];

    for (int i = 0; i < nr_cars; i++) {
        double speed = cars[i]->GetSpeed(weather);
        double consumption = cars[i]->GetFuel_Consumption();
        double dist = len;

        races[i].time = dist/speed;
        races[i].fuel_needed = (consumption*dist)/100.0;

        const char* car_name = cars[i]->GetName();
        races[i].nr_letters = cars[i]->GetNr_letters();
        races[i].name = new char[races[i].nr_letters];
        for (int j = 0; j < races[i].nr_letters; j++) {
            races[i].name[j] = car_name[j];
        }

        races[i].finished = (races[i].fuel_needed <= cars[i]->GetFuel_Capacity());
    }
}

void Circuit::ShowFinalRanks() {
    for (int i = 0; i<nr_cars-1; i++) {
        for (int j = i+1; j<nr_cars; j++) {
            if (races[i].time>=races[j].time) {
                RaceResult temp = races[i];
                races[i] = races[j];
                races[j] = temp;
            }
        }
    }
    int rank = 0;
    printf("Final Ranks: \n");
    for (int i = 0; i<nr_cars; i++) {
        if (races[i].finished==true&&races[i].finished==true) {
            rank++;
            printf(" %d. %s \n", rank, races[i].name);
        }
    }
    if (rank==0) {
        printf("No cars finished the race");
    }
}

void Circuit::ShowWhoDidNotFinish() {
    int not_finished = 0;
    printf("Who Did not finish the race\n");
    for (int i = 0; i<nr_cars; i++) {
        if (races[i].finished==false) {
            not_finished++;
            printf(" %d. %s \n", not_finished, races[i].name);
        }
    }
    if (not_finished==0) {
        printf("All cars finished the race\n");
    }
}