
#include "carFactory.hpp"

#ifdef _DEBUG

#include "gmock/gmock.h"

int main() {
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}

#else
void printSelectionOfStep(CarFactory::CarPartType step);
void printSelectionOfRunAndTest();
void printSelectionOfSteeringSystem();
void printSelectionOfBrakeSystem();
void printSelectionOfEngine();
void printSelectionOfCarType();
void getUserSelection(char  buf[100]);
bool checkUserSelectionIsNumber(char  buf[100]);
bool exitSelected(char  buf[100]);

int main() {
	CarFactory carFactory;
    char userInputBuffer[100];
    CarFactory::CarPartType curSelectionStep = CarFactory::CarPartType::CarType_Q;

    while (1)
    {
        printSelectionOfStep(curSelectionStep);
        getUserSelection(userInputBuffer);
        if (exitSelected(userInputBuffer) == true) break;
        if (checkUserSelectionIsNumber(userInputBuffer) == false) continue;
        int selectedNumber = strtol(userInputBuffer, NULL, 10);

        curSelectionStep = carFactory.makePartOfCar(selectedNumber, curSelectionStep);
    }
	
}


void getUserSelection(char  buf[100])
{
    fgets(buf, sizeof(buf), stdin);

    // ���� ���๮�� ����
    char* context = nullptr;
    strtok_s(buf, "\r", &context);
    strtok_s(buf, "\n", &context);
}

bool exitSelected(char buf[100])
{
    bool isExitSelected = false;

    if (!strcmp(buf, "exit"))
    {
        printf("���̹���\n");
        isExitSelected = true;
    }

    return isExitSelected;
}


bool checkUserSelectionIsNumber(char  buf[100])
{
    bool isUserInputNumber = true;
    char* checkNumber;

    strtol(buf, &checkNumber, 10);

    if (*checkNumber != '\0')
    {
        printf("ERROR :: ���ڸ� �Է� ����\n");
        CarFactory::delay(800);
        isUserInputNumber = false;
    }

    return isUserInputNumber;

}

void printSelectionOfStep(CarFactory::CarPartType step)
{
    if (step == CarFactory::CarType_Q) printSelectionOfCarType();
    if (step == CarFactory::Engine_Q) printSelectionOfEngine();
    if (step == CarFactory::BrakeSystem_Q) printSelectionOfBrakeSystem();
    if (step == CarFactory::SteeringSystem_Q) printSelectionOfSteeringSystem();
    if (step == CarFactory::Run_Test)printSelectionOfRunAndTest();
    printf("===============================\n");
    printf("INPUT > ");
    return;
}


void printSelectionOfRunAndTest()
{
    printf(CLEAR_SCREEN);
    printf("���� ������ �ϼ��Ǿ����ϴ�.\n");
    printf("� ������ �ұ��?\n");
    printf("0. ó�� ȭ������ ���ư���\n");
    printf("1. RUN\n");
    printf("2. Test\n");
}

void printSelectionOfSteeringSystem()
{
    printf(CLEAR_SCREEN);
    printf("� ������ġ�� �����ұ��?\n");
    printf("0. �ڷΰ���\n");
    printf("1. BOSCH\n");
    printf("2. MOBIS\n");
}

void printSelectionOfBrakeSystem()
{
    printf(CLEAR_SCREEN);
    printf("� ������ġ�� �����ұ��?\n");
    printf("0. �ڷΰ���\n");
    printf("1. MANDO\n");
    printf("2. CONTINENTAL\n");
    printf("3. BOSCH\n");
}

void printSelectionOfEngine()
{
    printf(CLEAR_SCREEN);
    printf("� ������ ž���ұ��?\n");
    printf("0. �ڷΰ���\n");
    printf("1. GM\n");
    printf("2. TOYOTA\n");
    printf("3. WIA\n");
    printf("4. ���峭 ����\n");
}

void printSelectionOfCarType()
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

#endif