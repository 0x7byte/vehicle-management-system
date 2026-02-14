#ifndef INIT_H
#define INIT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX 200
#define CIZE 50
#define UNDO_MAX 200

#define NORMAL   "\033[0m" //for making normal to bold char [taken from geek for geeks]
#define BOLD    "\033[1m"  //for making bold to normal char [taken from geek for geeks]

// Undo actions
#define ACTION_ADD    1
#define ACTION_DELETE 2
#define ACTION_UPDATE 3

// Vehicle 
typedef struct {
    int id;
    char vehicleType[CIZE];
    char vehicleModel[CIZE];
    char vehicleBrand[CIZE];
    int year;
    int engineCC;
} Vehicle;

typedef struct{
    int engineCapacity;
}Car;

typedef struct{
    int seatCount;
}Bus;

typedef struct{
    float batterycapacity;
    int batteryHealth;
    float chargingTime;
}ElectricCar;

typedef union{
    Car car;
    Bus bus;
    ElectricCar eCar;
}vehicleDetails;

// the legendary Undo //var undoHistory
typedef struct {
    int action;
    Vehicle data;
    int index;
} Undo;

//GLobal data
extern Vehicle vehicles[MAX];
extern int vehicleCount;

// Functions
void addVehicle();
void showVehicles();
void updateVehicle();
void deleteVehicle();

int searchAny();
void bulkDelete();
void summaryReport();
int groupByType();
void undoLast();

#endif