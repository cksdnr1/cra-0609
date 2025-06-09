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

    // ���� ���๮�� ����
    char* context = nullptr;
    strtok_s(buf, "\r", &context);
    strtok_s(buf, "\n", &context);
}

bool CarFactory::exitSelected(char buf[100])
{
    bool isExitSelected = false;

    if (!strcmp(buf, "exit"))
    {
        printf("���̹���\n");
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
        printf("ERROR :: ���ڸ� �Է� ����\n");
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
            printf("ERROR :: ���� Ÿ���� 1 ~ 3 ������ ���� ����\n");
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
        printf("ERROR :: ������ 1 ~ 4 ������ ���� ����\n");
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
        printf("ERROR :: ������ġ�� 1 ~ 3 ������ ���� ����\n");
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
        printf("ERROR :: ������ġ�� 1 ~ 2 ������ ���� ����\n");
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
        printf("ERROR :: Run �Ǵ� Test �� �ϳ��� ���� �ʿ�\n");
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
    printf("���� ������ �ϼ��Ǿ����ϴ�.\n");
    printf("� ������ �ұ��?\n");
    printf("0. ó�� ȭ������ ���ư���\n");
    printf("1. RUN\n");
    printf("2. Test\n");
}

void CarFactory::printSelectionOfSteeringSystem()
{
    printf(CLEAR_SCREEN);
    printf("� ������ġ�� �����ұ��?\n");
    printf("0. �ڷΰ���\n");
    printf("1. BOSCH\n");
    printf("2. MOBIS\n");
}

void CarFactory::printSelectionOfBrakeSystem()
{
    printf(CLEAR_SCREEN);
    printf("� ������ġ�� �����ұ��?\n");
    printf("0. �ڷΰ���\n");
    printf("1. MANDO\n");
    printf("2. CONTINENTAL\n");
    printf("3. BOSCH\n");
}

void CarFactory::printSelectionOfEngine()
{
    printf(CLEAR_SCREEN);
    printf("� ������ ž���ұ��?\n");
    printf("0. �ڷΰ���\n");
    printf("1. GM\n");
    printf("2. TOYOTA\n");
    printf("3. WIA\n");
    printf("4. ���峭 ����\n");
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
    printf("� ���� Ÿ���� �����ұ��?\n");
    printf("1. Sedan\n");
    printf("2. SUV\n");
    printf("3. Truck\n");
}

void CarFactory::selectCarType(int selectedNumber)
{
    carPartStroage[CarType_Q] = selectedNumber;
    if (selectedNumber == CarType::SEDAN)
        printf("���� Ÿ������ Sedan�� �����ϼ̽��ϴ�.\n");
    if (selectedNumber == CarType::SUV)
        printf("���� Ÿ������ SUV�� �����ϼ̽��ϴ�.\n");
    if (selectedNumber == CarType::TRUCK)
        printf("���� Ÿ������ Truck�� �����ϼ̽��ϴ�.\n");
}

void CarFactory::selectEngine(int selectedNumber)
{
    carPartStroage[Engine_Q] = selectedNumber;
    if (selectedNumber == Engine::GM)
        printf("GM ������ �����ϼ̽��ϴ�.\n");
    if (selectedNumber == Engine::TOYOTA)
        printf("TOYOTA ������ �����ϼ̽��ϴ�.\n");
    if (selectedNumber == Engine::WIA)
        printf("WIA ������ �����ϼ̽��ϴ�.\n");
}

void CarFactory::selectbrakeSystem(int selectedNumber)
{
    carPartStroage[BrakeSystem_Q] = selectedNumber;
    if (selectedNumber == BrakeSystem::MANDO)
        printf("MANDO ������ġ�� �����ϼ̽��ϴ�.\n");
    if (selectedNumber == BrakeSystem::CONTINENTAL)
        printf("CONTINENTAL ������ġ�� �����ϼ̽��ϴ�.\n");
    if (selectedNumber == BrakeSystem::BOSCH_B)
        printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
}

void CarFactory::selectSteeringSystem(int selectedNumber)
{
    carPartStroage[SteeringSystem_Q] = selectedNumber;
    if (selectedNumber == SteeringSystem::BOSCH_S)
        printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
    if (selectedNumber == SteeringSystem::MOBIS)
        printf("MOBIS ������ġ�� �����ϼ̽��ϴ�.\n");
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
        printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
        return;
    }

    if (carPartStroage[Engine_Q] == Engine::InvalidEngine)
    {
        printf("������ ���峪�ֽ��ϴ�.\n");
        printf("�ڵ����� �������� �ʽ��ϴ�.\n");
        return;
    }

    proceedCarType();
    proceedEngine();
    proceedBrakeSystem();
    proceedSteeringSystem();

    printf("�ڵ����� ���۵˴ϴ�.\n");
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
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Sedan���� Continental������ġ ��� �Ұ�\n");
    }
    else if (carPartStroage[CarType_Q] == SUV && carPartStroage[Engine_Q] == TOYOTA)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("SUV���� TOYOTA���� ��� �Ұ�\n");
    }
    else if (carPartStroage[CarType_Q] == TRUCK && carPartStroage[Engine_Q] == WIA)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Truck���� WIA���� ��� �Ұ�\n");
    }
    else if (carPartStroage[CarType_Q] == TRUCK && carPartStroage[BrakeSystem_Q] == MANDO)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Truck���� Mando������ġ ��� �Ұ�\n");
    }
    else if (carPartStroage[BrakeSystem_Q] == BOSCH_B && carPartStroage[SteeringSystem_Q] != BOSCH_S)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Bosch�������� Bosch������ġ �̿� ��� �Ұ�\n");
    }
    else
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
    }
}
