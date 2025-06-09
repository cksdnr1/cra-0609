#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory>

#define CLEAR_SCREEN "\033[H\033[2J"

const int REWIND = 0;

class IPartBuilder;

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
    CarPartType makePartOfCar(int selectedNumber, CarPartType curSelectionStep);

    static void delay(int ms)
    {
        volatile int sum = 0;
        for (int i = 0; i < 1000; i++)
        {
            for (int j = 0; j < 1000; j++)
            {
                for (int t = 0; t < ms; t++)
                {
                    sum++;
                }
            }
        }
    }

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
    std::shared_ptr<IPartBuilder> selectPartBuilder(int selectedNumber, CarPartType curSelectionStep);
    CarPartType selectRunAndTest(int selectedNumber, CarPartType curSelectionStep);

    int isValidCheck();

private:
    int carPartStorage[10];
};

class IPartBuilder {
public:
    virtual CarFactory::CarPartType selectStep(int selectedNumber, CarFactory::CarPartType curSelectionStep, int carPartStroage[]) = 0;
    virtual void buildPart(int selectedNumber, int carPartStorage[]) =0;
};

class CarTypeBuilder : public IPartBuilder {
public:
    CarFactory::CarPartType selectStep(int selectedNumber, CarFactory::CarPartType curSelectionStep, int carPartStroage[]) override;
    void buildPart(int selectedNumber, int carPartStorage[]) override;
};

class EngineTypeBuilder : public IPartBuilder {
public:
    CarFactory::CarPartType selectStep(int selectedNumber,
        CarFactory::CarPartType curSelectionStep, int carPartStroage[]) override;
    void buildPart(int selectedNumber, int carPartStorage[]) override;
};

class BrakeSystemBuilder : public IPartBuilder {
public:
    CarFactory::CarPartType selectStep(int selectedNumber,
        CarFactory::CarPartType curSelectionStep, int carPartStroage[]) override;
    void buildPart(int selectedNumber, int carPartStorage[]) override;
};

class SteeringSystemBuilder : public IPartBuilder {
public:
    CarFactory::CarPartType selectStep(int selectedNumber,
        CarFactory::CarPartType curSelectionStep, int carPartStroage[]) override;
    void buildPart(int selectedNumber, int carPartStorage[]) override;
};