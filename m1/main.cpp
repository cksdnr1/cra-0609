#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CLEAR_SCREEN "\033[H\033[2J"


enum CarPartType
{
    CarType_Q,
    Engine_Q,
    BrakeSystem_Q,
    SteeringSystem_Q,
    Run_Test,
};

enum CarType
{
    SEDAN = 1,
    SUV,
    TRUCK
};

enum Engine
{
    GM = 1,
    TOYOTA,
    WIA,
    InvalidEngine
};

enum BrakeSystem
{
    MANDO = 1,
    CONTINENTAL,
    BOSCH_B
};

enum SteeringSystem
{
    BOSCH_S = 1,
    MOBIS
};

enum RunAndTest
{
    RUN = 1,
    TEST
};

const int REWIND = 0;

int stack[10];

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
void delay(int ms);

CarPartType makePartOfCar(int selectedNumber, CarPartType curSelectionStep);

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

int main()
{
    char userInputBuffer[100];
    CarPartType curSelectionStep = CarType_Q;

    while (1)
    {
        printSelectionOfStep(curSelectionStep);
        getUserSelection(userInputBuffer);
        if (exitSelected(userInputBuffer)==true) break;
        if (checkUserSelectionIsNumber(userInputBuffer) == false) continue;
        int selectedNumber = strtol(userInputBuffer, NULL, 10);
        curSelectionStep = makePartOfCar(selectedNumber, curSelectionStep);  
    }
}

void printSelectionOfStep(CarPartType step)
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
        delay(800);
        isUserInputNumber = false;
    }

    return isUserInputNumber;

}

CarPartType makePartOfCar(int selectedNumber, CarPartType curSelectionStep)
{
    if (curSelectionStep == CarType_Q) return selectCarType(selectedNumber, curSelectionStep);
    if (curSelectionStep == Engine_Q) return selectEngineType(selectedNumber, curSelectionStep);
    if (curSelectionStep == BrakeSystem_Q) return selectBrakeSystem(selectedNumber, curSelectionStep);
    if (curSelectionStep == SteeringSystem_Q) return selectSteeringSystem(selectedNumber, curSelectionStep); 
    if (curSelectionStep == Run_Test) return selectRunAndTest(selectedNumber, curSelectionStep);
    return CarPartType::CarType_Q;
}

CarPartType selectCarType(int selectedNumber, CarPartType curSelectionStep)
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

CarPartType selectEngineType(int selectedNumber, CarPartType curSelectionStep)
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

CarPartType selectBrakeSystem(int selectedNumber, CarPartType curSelectionStep)
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

CarPartType selectSteeringSystem(int selectedNumber, CarPartType curSelectionStep)
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

CarPartType selectRunAndTest(int selectedNumber, CarPartType curSelectionStep)
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

void selectCarType(int selectedNumber)
{
    stack[CarType_Q] = selectedNumber;
    if (selectedNumber == CarType::SEDAN)
        printf("���� Ÿ������ Sedan�� �����ϼ̽��ϴ�.\n");
    if (selectedNumber == CarType::SUV)
        printf("���� Ÿ������ SUV�� �����ϼ̽��ϴ�.\n");
    if (selectedNumber == CarType::TRUCK)
        printf("���� Ÿ������ Truck�� �����ϼ̽��ϴ�.\n");
}

void selectEngine(int selectedNumber)
{
    stack[Engine_Q] = selectedNumber;
    if (selectedNumber == Engine::GM)
        printf("GM ������ �����ϼ̽��ϴ�.\n");
    if (selectedNumber == Engine::TOYOTA)
        printf("TOYOTA ������ �����ϼ̽��ϴ�.\n");
    if (selectedNumber == Engine::WIA)
        printf("WIA ������ �����ϼ̽��ϴ�.\n");
}

void selectbrakeSystem(int selectedNumber)
{
    stack[BrakeSystem_Q] = selectedNumber;
    if (selectedNumber == BrakeSystem::MANDO)
        printf("MANDO ������ġ�� �����ϼ̽��ϴ�.\n");
    if (selectedNumber == BrakeSystem::CONTINENTAL)
        printf("CONTINENTAL ������ġ�� �����ϼ̽��ϴ�.\n");
    if (selectedNumber == BrakeSystem::BOSCH_B)
        printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
}

void selectSteeringSystem(int selectedNumber)
{
    stack[SteeringSystem_Q] = selectedNumber;
    if (selectedNumber == SteeringSystem::BOSCH_S)
        printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
    if (selectedNumber == SteeringSystem::MOBIS)
        printf("MOBIS ������ġ�� �����ϼ̽��ϴ�.\n");
}

int isValidCheck()
{
    if (stack[CarType_Q] == SEDAN && stack[BrakeSystem_Q] == CONTINENTAL)
    {
        return false;
    }
    else if (stack[CarType_Q] == SUV && stack[Engine_Q] == TOYOTA)
    {
        return false;
    }
    else if (stack[CarType_Q] == TRUCK && stack[Engine_Q] == WIA)
    {
        return false;
    }
    else if (stack[CarType_Q] == TRUCK && stack[BrakeSystem_Q] == MANDO)
    {
        return false;
    }
    else if (stack[BrakeSystem_Q] == BOSCH_B && stack[SteeringSystem_Q] != BOSCH_S)
    {
        return false;
    }
    else
    {
        return true;
    }
    return true;
}

void runProducedCar()
{
    if (isValidCheck() == false)
    {
        printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
        return;
    }

    if (stack[Engine_Q] == Engine::InvalidEngine)
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

void proceedSteeringSystem()
{
    if (stack[SteeringSystem_Q] == SteeringSystem::BOSCH_S)
        printf("SteeringSystem : Bosch\n");
    if (stack[SteeringSystem_Q] == SteeringSystem::MOBIS)
        printf("SteeringSystem : Mobis\n");
}

void proceedBrakeSystem()
{
    if (stack[BrakeSystem_Q] == BrakeSystem::MANDO)
        printf("Brake System : Mando");
    if (stack[BrakeSystem_Q] == BrakeSystem::CONTINENTAL)
        printf("Brake System : Continental\n");
    if (stack[BrakeSystem_Q] == BrakeSystem::BOSCH_B)
        printf("Brake System : Bosch\n");
}

void proceedEngine()
{
    if (stack[Engine_Q] == Engine::GM)
        printf("Engine : GM\n");
    if (stack[Engine_Q] == Engine::TOYOTA)
        printf("Engine : TOYOTA\n");
    if (stack[Engine_Q] == Engine::WIA)
        printf("Engine : WIA\n");
}

void proceedCarType()
{
    if (stack[CarType_Q] == CarType::SEDAN)
        printf("Car Type : Sedan\n");
    if (stack[CarType_Q] == CarType::SUV)
        printf("Car Type : SUV\n");
    if (stack[CarType_Q] == CarType::TRUCK)
        printf("Car Type : Truck\n");
}

void testProducedCar()
{
    if (stack[CarType_Q] == SEDAN && stack[BrakeSystem_Q] == CONTINENTAL)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Sedan���� Continental������ġ ��� �Ұ�\n");
    }
    else if (stack[CarType_Q] == SUV && stack[Engine_Q] == TOYOTA)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("SUV���� TOYOTA���� ��� �Ұ�\n");
    }
    else if (stack[CarType_Q] == TRUCK && stack[Engine_Q] == WIA)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Truck���� WIA���� ��� �Ұ�\n");
    }
    else if (stack[CarType_Q] == TRUCK && stack[BrakeSystem_Q] == MANDO)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Truck���� Mando������ġ ��� �Ұ�\n");
    }
    else if (stack[BrakeSystem_Q] == BOSCH_B && stack[SteeringSystem_Q] != BOSCH_S)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Bosch�������� Bosch������ġ �̿� ��� �Ұ�\n");
    }
    else
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
    }
}