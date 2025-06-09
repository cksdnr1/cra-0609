#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CLEAR_SCREEN "\033[H\033[2J"

const int REWIND = 0;



class CarFactory {
public:
    enum CarPartType
    {
        CarType_Q,
        Engine_Q,
        BrakeSystem_Q,
        SteeringSystem_Q,
        Run_Test,
        EMPTY_Q,
    };

    enum CarType
    {
        SEDAN = 1,
        SUV,
        TRUCK,
        EMPTY_C
    };

    enum Engine
    {
        GM = 1,
        TOYOTA,
        WIA,
        InvalidEngine,
        EMPTY_E
    };

    enum BrakeSystem
    {
        MANDO = 1,
        CONTINENTAL,
        BOSCH_B,
        EMPTY_B
    };

    enum SteeringSystem
    {
        BOSCH_S = 1,
        MOBIS,
        EMPTY_S
    };

    enum RunAndTest
    {
        RUN = 1,
        TEST,
        EMPTY_R
    };

public:
    CarFactory() {};
    void makeCar();
    CarPartType makePartOfCar(int selectedNumber, CarPartType curSelectionStep);

private:
    void selectCarType(int answer);
    void selectEngine(int answer);
    void selectbrakeSystem(int answer);
    void selectSteeringSystem(int answer);
    void runProducedCar();
    void proceedSteeringSystem();
    void proceedBrakeSystem();
    void proceedEngine();
    void proceedCarType();
    void testProducedCar();
   

    

    CarPartType selectRunAndTest(int selectedNumber, CarPartType curSelectionStep);

    CarPartType selectSteeringSystem(int selectedNumber, CarPartType curSelectionStep);

    CarPartType selectBrakeSystem(int selectedNumber, CarPartType curSelectionStep);

    CarPartType selectEngineType(int selectedNumber, CarPartType curSelectionStep);

    CarPartType selectCarType(int selectedNumber, CarPartType step);

    bool checkUserSelectionIsNumber(char  buf[100]);

    void getUserSelection(char  buf[100]);

    bool exitSelected(char  buf[100]);

    void printSelectionOfStep(CarPartType step);

    void printSelectionOfRunAndTest();

    void printSelectionOfSteeringSystem();

    void printSelectionOfBrakeSystem();

    void printSelectionOfEngine();

    void printSelectionOfCarType();
    int isValidCheck();

private:
    int carPartStroage[10];
    
    CarPartType curSelectionStep = CarType_Q;

};
