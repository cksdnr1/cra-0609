#include "carFactory.hpp"
#pragma once

void delay(int ms)
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

void CarFactory::makeCar()
{
    char userInputBuffer[100];
    while (1)
    {
        printSelectionOfStep(curSelectionStep);
        getUserSelection(userInputBuffer);
        if (exitSelected(userInputBuffer) == true) break;
        if (checkUserSelectionIsNumber(userInputBuffer) == false) continue;
        int selectedNumber = strtol(userInputBuffer, NULL, 10);
        curSelectionStep = makePartOfCar(selectedNumber, curSelectionStep);
    }
}

void CarFactory::printSelectionOfStep(CarPartType step)
{
    if (step == CarType_Q) printSelectionOfCarType();
    if (step == Engine_Q) printSelectionOfEngine();
    if (step == BrakeSystem_Q) printSelectionOfBrakeSystem();
    if (step == SteeringSystem_Q) printSelectionOfSteeringSystem();
    if (step == Run_Test)printSelectionOfRunAndTest();
    printf("===============================\n");
    printf("INPUT > ");
    return;
}


void CarFactory::getUserSelection(char  buf[100])
{
    fgets(buf, sizeof(buf), stdin);

    // 엔터 개행문자 제거
    char* context = nullptr;
    strtok_s(buf, "\r", &context);
    strtok_s(buf, "\n", &context);
}

bool CarFactory::exitSelected(char buf[100])
{
    bool isExitSelected = false;

    if (!strcmp(buf, "exit"))
    {
        printf("바이바이\n");
        isExitSelected = true;
    }

    return isExitSelected;
}


bool CarFactory::checkUserSelectionIsNumber(char  buf[100])
{
    bool isUserInputNumber = true;
    char* checkNumber;

    strtol(buf, &checkNumber, 10);

    if (*checkNumber != '\0')
    {
        printf("ERROR :: 숫자만 입력 가능\n");
        delay(800);
        isUserInputNumber = false;
    }

    return isUserInputNumber;

}

CarFactory::CarPartType CarFactory::makePartOfCar(int selectedNumber, CarPartType curSelectionStep)
{
    if (curSelectionStep == CarType_Q) return selectCarType(selectedNumber, curSelectionStep);
    if (curSelectionStep == Engine_Q) return selectEngineType(selectedNumber, curSelectionStep);
    if (curSelectionStep == BrakeSystem_Q) return selectBrakeSystem(selectedNumber, curSelectionStep);
    if (curSelectionStep == SteeringSystem_Q) return selectSteeringSystem(selectedNumber, curSelectionStep);
    if (curSelectionStep == Run_Test) return selectRunAndTest(selectedNumber, curSelectionStep);
    return CarPartType::CarType_Q;
}

CarFactory::CarPartType CarFactory::CarFactory::selectCarType(int selectedNumber, CarPartType curSelectionStep)
    {
        if ((selectedNumber >= 1 && selectedNumber <= 3) == false) {
            printf("ERROR :: 차량 타입은 1 ~ 3 범위만 선택 가능\n");
            delay(800);
            return curSelectionStep;
        }

        selectCarType(selectedNumber);
        delay(800);
        return CarPartType::Engine_Q;
    }

CarFactory::CarPartType CarFactory::selectEngineType(int selectedNumber, CarPartType curSelectionStep)
{
    if ((selectedNumber >= 0 && selectedNumber <= 4) == false) {
        printf("ERROR :: 엔진은 1 ~ 4 범위만 선택 가능\n");
        delay(800);
        return curSelectionStep;
    }

    if (selectedNumber == REWIND) return CarPartType::CarType_Q;

    selectEngine(selectedNumber);
    delay(800);
    return  CarPartType::BrakeSystem_Q;
}

CarFactory::CarPartType CarFactory::selectBrakeSystem(int selectedNumber, CarPartType curSelectionStep)
{
    if ((selectedNumber >= 0 && selectedNumber <= 3) == false) {
        printf("ERROR :: 제동장치는 1 ~ 3 범위만 선택 가능\n");
        delay(800);
        return curSelectionStep;
    }

    if (selectedNumber == REWIND) return CarPartType::Engine_Q;

    selectbrakeSystem(selectedNumber);
    delay(800);
    return CarPartType::SteeringSystem_Q;
}

CarFactory::CarPartType CarFactory::selectSteeringSystem(int selectedNumber, CarPartType curSelectionStep)
{
    if ((selectedNumber >= 0 && selectedNumber <= 2) == false) {
        printf("ERROR :: 조향장치는 1 ~ 2 범위만 선택 가능\n");
        delay(800);
        return curSelectionStep;
    }

    if (selectedNumber == REWIND) return CarPartType::BrakeSystem_Q;

    selectSteeringSystem(selectedNumber);
    delay(800);
    return  CarPartType::Run_Test;
}

CarFactory::CarPartType CarFactory::selectRunAndTest(int selectedNumber, CarPartType curSelectionStep)
{
    if ((selectedNumber >= 0 && selectedNumber <= 2) == false) {
        printf("ERROR :: Run 또는 Test 중 하나를 선택 필요\n");
        delay(800);
        return curSelectionStep;
    }

    if (selectedNumber == REWIND) {
        return CarPartType::CarType_Q;
    }

    if (selectedNumber == RUN) {
        runProducedCar();
        delay(2000);
        return curSelectionStep;
    }

    if (selectedNumber == TEST) {
        printf("Test...\n");
        delay(1500);
        testProducedCar();
        delay(2000);
        return curSelectionStep;
    }
}

void CarFactory::printSelectionOfRunAndTest()
{
    printf(CLEAR_SCREEN);
    printf("멋진 차량이 완성되었습니다.\n");
    printf("어떤 동작을 할까요?\n");
    printf("0. 처음 화면으로 돌아가기\n");
    printf("1. RUN\n");
    printf("2. Test\n");
}

void CarFactory::printSelectionOfSteeringSystem()
{
    printf(CLEAR_SCREEN);
    printf("어떤 조향장치를 선택할까요?\n");
    printf("0. 뒤로가기\n");
    printf("1. BOSCH\n");
    printf("2. MOBIS\n");
}

void CarFactory::printSelectionOfBrakeSystem()
{
    printf(CLEAR_SCREEN);
    printf("어떤 제동장치를 선택할까요?\n");
    printf("0. 뒤로가기\n");
    printf("1. MANDO\n");
    printf("2. CONTINENTAL\n");
    printf("3. BOSCH\n");
}

void CarFactory::printSelectionOfEngine()
{
    printf(CLEAR_SCREEN);
    printf("어떤 엔진을 탑재할까요?\n");
    printf("0. 뒤로가기\n");
    printf("1. GM\n");
    printf("2. TOYOTA\n");
    printf("3. WIA\n");
    printf("4. 고장난 엔진\n");
}

void CarFactory::printSelectionOfCarType()
{
    printf(CLEAR_SCREEN);

    printf("        ______________\n");
    printf("       /|            | \n");
    printf("  ____/_|_____________|____\n");
    printf(" |                      O  |\n");
    printf(" '-(@)----------------(@)--'\n");
    printf("===============================\n");
    printf("어떤 차량 타입을 선택할까요?\n");
    printf("1. Sedan\n");
    printf("2. SUV\n");
    printf("3. Truck\n");
}

void CarFactory::selectCarType(int selectedNumber)
{
    carPartStroage[CarType_Q] = selectedNumber;
    if (selectedNumber == CarType::SEDAN)
        printf("차량 타입으로 Sedan을 선택하셨습니다.\n");
    if (selectedNumber == CarType::SUV)
        printf("차량 타입으로 SUV을 선택하셨습니다.\n");
    if (selectedNumber == CarType::TRUCK)
        printf("차량 타입으로 Truck을 선택하셨습니다.\n");
}

void CarFactory::selectEngine(int selectedNumber)
{
    carPartStroage[Engine_Q] = selectedNumber;
    if (selectedNumber == Engine::GM)
        printf("GM 엔진을 선택하셨습니다.\n");
    if (selectedNumber == Engine::TOYOTA)
        printf("TOYOTA 엔진을 선택하셨습니다.\n");
    if (selectedNumber == Engine::WIA)
        printf("WIA 엔진을 선택하셨습니다.\n");
}

void CarFactory::selectbrakeSystem(int selectedNumber)
{
    carPartStroage[BrakeSystem_Q] = selectedNumber;
    if (selectedNumber == BrakeSystem::MANDO)
        printf("MANDO 제동장치를 선택하셨습니다.\n");
    if (selectedNumber == BrakeSystem::CONTINENTAL)
        printf("CONTINENTAL 제동장치를 선택하셨습니다.\n");
    if (selectedNumber == BrakeSystem::BOSCH_B)
        printf("BOSCH 제동장치를 선택하셨습니다.\n");
}

void CarFactory::selectSteeringSystem(int selectedNumber)
{
    carPartStroage[SteeringSystem_Q] = selectedNumber;
    if (selectedNumber == SteeringSystem::BOSCH_S)
        printf("BOSCH 조향장치를 선택하셨습니다.\n");
    if (selectedNumber == SteeringSystem::MOBIS)
        printf("MOBIS 조향장치를 선택하셨습니다.\n");
}

int CarFactory::isValidCheck()
{
    if (carPartStroage[CarType_Q] == SEDAN && carPartStroage[BrakeSystem_Q] == CONTINENTAL)return false;
    if (carPartStroage[CarType_Q] == SUV && carPartStroage[Engine_Q] == TOYOTA)return false;
    if (carPartStroage[CarType_Q] == TRUCK && carPartStroage[Engine_Q] == WIA) return false;
    if (carPartStroage[CarType_Q] == TRUCK && carPartStroage[BrakeSystem_Q] == MANDO) return false;
    if (carPartStroage[BrakeSystem_Q] == BOSCH_B && carPartStroage[SteeringSystem_Q] != BOSCH_S)return false;

    return true;
}

void CarFactory::runProducedCar()
{
    if (isValidCheck() == false)
    {
        printf("자동차가 동작되지 않습니다\n");
        return;
    }

    if (carPartStroage[Engine_Q] == Engine::InvalidEngine)
    {
        printf("엔진이 고장나있습니다.\n");
        printf("자동차가 움직이지 않습니다.\n");
        return;
    }

    proceedCarType();
    proceedEngine();
    proceedBrakeSystem();
    proceedSteeringSystem();

    printf("자동차가 동작됩니다.\n");
}

void CarFactory::proceedSteeringSystem()
{
    if (carPartStroage[SteeringSystem_Q] == SteeringSystem::BOSCH_S)
        printf("SteeringSystem : Bosch\n");
    if (carPartStroage[SteeringSystem_Q] == SteeringSystem::MOBIS)
        printf("SteeringSystem : Mobis\n");
}

void CarFactory::proceedBrakeSystem()
{
    if (carPartStroage[BrakeSystem_Q] == BrakeSystem::MANDO)
        printf("Brake System : Mando");
    if (carPartStroage[BrakeSystem_Q] == BrakeSystem::CONTINENTAL)
        printf("Brake System : Continental\n");
    if (carPartStroage[BrakeSystem_Q] == BrakeSystem::BOSCH_B)
        printf("Brake System : Bosch\n");
}

void CarFactory::proceedEngine()
{
    if (carPartStroage[Engine_Q] == Engine::GM)
        printf("Engine : GM\n");
    if (carPartStroage[Engine_Q] == Engine::TOYOTA)
        printf("Engine : TOYOTA\n");
    if (carPartStroage[Engine_Q] == Engine::WIA)
        printf("Engine : WIA\n");
}

void CarFactory::proceedCarType()
{
    if (carPartStroage[CarType_Q] == CarType::SEDAN)
        printf("Car Type : Sedan\n");
    if (carPartStroage[CarType_Q] == CarType::SUV)
        printf("Car Type : SUV\n");
    if (carPartStroage[CarType_Q] == CarType::TRUCK)
        printf("Car Type : Truck\n");
}

void CarFactory::testProducedCar()
{
    if (carPartStroage[CarType_Q] == SEDAN && carPartStroage[BrakeSystem_Q] == CONTINENTAL)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Sedan에는 Continental제동장치 사용 불가\n");
    }
    else if (carPartStroage[CarType_Q] == SUV && carPartStroage[Engine_Q] == TOYOTA)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("SUV에는 TOYOTA엔진 사용 불가\n");
    }
    else if (carPartStroage[CarType_Q] == TRUCK && carPartStroage[Engine_Q] == WIA)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Truck에는 WIA엔진 사용 불가\n");
    }
    else if (carPartStroage[CarType_Q] == TRUCK && carPartStroage[BrakeSystem_Q] == MANDO)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Truck에는 Mando제동장치 사용 불가\n");
    }
    else if (carPartStroage[BrakeSystem_Q] == BOSCH_B && carPartStroage[SteeringSystem_Q] != BOSCH_S)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Bosch엔진에는 Bosch조향장치 이외 사용 불가\n");
    }
    else
    {
        printf("자동차 부품 조합 테스트 결과 : PASS\n");
    }
}
