
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

    // 엔터 개행문자 제거
    char* context = nullptr;
    strtok_s(buf, "\r", &context);
    strtok_s(buf, "\n", &context);
}

bool exitSelected(char buf[100])
{
    bool isExitSelected = false;

    if (!strcmp(buf, "exit"))
    {
        printf("바이바이\n");
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
        printf("ERROR :: 숫자만 입력 가능\n");
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
    printf("멋진 차량이 완성되었습니다.\n");
    printf("어떤 동작을 할까요?\n");
    printf("0. 처음 화면으로 돌아가기\n");
    printf("1. RUN\n");
    printf("2. Test\n");
}

void printSelectionOfSteeringSystem()
{
    printf(CLEAR_SCREEN);
    printf("어떤 조향장치를 선택할까요?\n");
    printf("0. 뒤로가기\n");
    printf("1. BOSCH\n");
    printf("2. MOBIS\n");
}

void printSelectionOfBrakeSystem()
{
    printf(CLEAR_SCREEN);
    printf("어떤 제동장치를 선택할까요?\n");
    printf("0. 뒤로가기\n");
    printf("1. MANDO\n");
    printf("2. CONTINENTAL\n");
    printf("3. BOSCH\n");
}

void printSelectionOfEngine()
{
    printf(CLEAR_SCREEN);
    printf("어떤 엔진을 탑재할까요?\n");
    printf("0. 뒤로가기\n");
    printf("1. GM\n");
    printf("2. TOYOTA\n");
    printf("3. WIA\n");
    printf("4. 고장난 엔진\n");
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
    printf("어떤 차량 타입을 선택할까요?\n");
    printf("1. Sedan\n");
    printf("2. SUV\n");
    printf("3. Truck\n");
}

#endif