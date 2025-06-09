#include "carFactory.hpp"
#pragma once

CarFactory::CarPartType CarFactory::makePartOfCar(int selectedNumber, CarPartType curSelectionStep)
{
    if (curSelectionStep == Run_Test) return selectRunAndTest(selectedNumber, curSelectionStep);
    
    std::shared_ptr<IPartBuilder> partBuilder = selectPartBuilder(selectedNumber, curSelectionStep);
    return partBuilder->selectStep(selectedNumber, curSelectionStep, carPartStorage);
}

std::shared_ptr<IPartBuilder> CarFactory::selectPartBuilder(int selectedNumber, CarPartType curSelectionStep)
{
    if (curSelectionStep == CarType_Q) return std::make_shared<CarTypeBuilder>();
    if (curSelectionStep == Engine_Q) return std::make_shared<EngineTypeBuilder>();
    if (curSelectionStep == BrakeSystem_Q) return std::make_shared<BrakeSystemBuilder>();
    if (curSelectionStep == SteeringSystem_Q) return std::make_shared<SteeringSystemBuilder>();
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

int CarFactory::isValidCheck()
{
    if (carPartStorage[CarType_Q] == SEDAN && carPartStorage[BrakeSystem_Q] == CONTINENTAL)return false;
    if (carPartStorage[CarType_Q] == SUV && carPartStorage[Engine_Q] == TOYOTA)return false;
    if (carPartStorage[CarType_Q] == TRUCK && carPartStorage[Engine_Q] == WIA) return false;
    if (carPartStorage[CarType_Q] == TRUCK && carPartStorage[BrakeSystem_Q] == MANDO) return false;
    if (carPartStorage[BrakeSystem_Q] == BOSCH_B && carPartStorage[SteeringSystem_Q] != BOSCH_S)return false;

    return true;
}

void CarFactory::runProducedCar()
{
    if (isValidCheck() == false)
    {
        printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
        return;
    }

    if (carPartStorage[Engine_Q] == Engine::InvalidEngine)
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
    if (carPartStorage[SteeringSystem_Q] == SteeringSystem::BOSCH_S)
        printf("SteeringSystem : Bosch\n");
    if (carPartStorage[SteeringSystem_Q] == SteeringSystem::MOBIS)
        printf("SteeringSystem : Mobis\n");
}

void CarFactory::proceedBrakeSystem()
{
    if (carPartStorage[BrakeSystem_Q] == BrakeSystem::MANDO)
        printf("Brake System : Mando");
    if (carPartStorage[BrakeSystem_Q] == BrakeSystem::CONTINENTAL)
        printf("Brake System : Continental\n");
    if (carPartStorage[BrakeSystem_Q] == BrakeSystem::BOSCH_B)
        printf("Brake System : Bosch\n");
}

void CarFactory::proceedEngine()
{
    if (carPartStorage[Engine_Q] == Engine::GM)
        printf("Engine : GM\n");
    if (carPartStorage[Engine_Q] == Engine::TOYOTA)
        printf("Engine : TOYOTA\n");
    if (carPartStorage[Engine_Q] == Engine::WIA)
        printf("Engine : WIA\n");
}

void CarFactory::proceedCarType()
{
    if (carPartStorage[CarType_Q] == CarType::SEDAN)
        printf("Car Type : Sedan\n");
    if (carPartStorage[CarType_Q] == CarType::SUV)
        printf("Car Type : SUV\n");
    if (carPartStorage[CarType_Q] == CarType::TRUCK)
        printf("Car Type : Truck\n");
}

void CarFactory::testProducedCar()
{
    if (carPartStorage[CarType_Q] == SEDAN && carPartStorage[BrakeSystem_Q] == CONTINENTAL)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Sedan���� Continental������ġ ��� �Ұ�\n");
    }
    else if (carPartStorage[CarType_Q] == SUV && carPartStorage[Engine_Q] == TOYOTA)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("SUV���� TOYOTA���� ��� �Ұ�\n");
    }
    else if (carPartStorage[CarType_Q] == TRUCK && carPartStorage[Engine_Q] == WIA)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Truck���� WIA���� ��� �Ұ�\n");
    }
    else if (carPartStorage[CarType_Q] == TRUCK && carPartStorage[BrakeSystem_Q] == MANDO)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Truck���� Mando������ġ ��� �Ұ�\n");
    }
    else if (carPartStorage[BrakeSystem_Q] == BOSCH_B && carPartStorage[SteeringSystem_Q] != BOSCH_S)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Bosch�������� Bosch������ġ �̿� ��� �Ұ�\n");
    }
    else
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
    }
}

CarFactory::CarPartType CarTypeBuilder::selectStep(int selectedNumber,
    CarFactory::CarPartType curSelectionStep, int carPartStorage[]) {
    if ((selectedNumber >= 1 && selectedNumber <= 3) == false) {
        printf("ERROR :: ���� Ÿ���� 1 ~ 3 ������ ���� ����\n");
        CarFactory::delay(800);
        return curSelectionStep;
    }

    buildPart(selectedNumber, carPartStorage);
    CarFactory::delay(800);
    return CarFactory::CarPartType::Engine_Q;
};

void CarTypeBuilder::buildPart(int selectedNumber, int carPartStorage[]) {
    carPartStorage[CarFactory::CarType_Q] = selectedNumber;
    if (selectedNumber == CarFactory::CarType::SEDAN)
        printf("���� Ÿ������ Sedan�� �����ϼ̽��ϴ�.\n");
    if (selectedNumber == CarFactory::CarType::SUV)
        printf("���� Ÿ������ SUV�� �����ϼ̽��ϴ�.\n");
    if (selectedNumber == CarFactory::CarType::TRUCK)
        printf("���� Ÿ������ Truck�� �����ϼ̽��ϴ�.\n");
};

CarFactory::CarPartType EngineTypeBuilder::selectStep(int selectedNumber,
    CarFactory::CarPartType curSelectionStep, int carPartStorage[]) {
    if ((selectedNumber >= 0 && selectedNumber <= 4) == false) {
        printf("ERROR :: ������ 1 ~ 4 ������ ���� ����\n");
        CarFactory::delay(800);
        return curSelectionStep;
    }

    if (selectedNumber == REWIND) return CarFactory::CarPartType::CarType_Q;

    buildPart(selectedNumber, carPartStorage);
    CarFactory::delay(800);
    return  CarFactory::CarPartType::BrakeSystem_Q;
};

void EngineTypeBuilder::buildPart(int selectedNumber, int carPartStorage[]) {
    carPartStorage[CarFactory::Engine_Q] = selectedNumber;
    if (selectedNumber == CarFactory::Engine::GM)
        printf("GM ������ �����ϼ̽��ϴ�.\n");
    if (selectedNumber == CarFactory::Engine::TOYOTA)
        printf("TOYOTA ������ �����ϼ̽��ϴ�.\n");
    if (selectedNumber == CarFactory::Engine::WIA)
        printf("WIA ������ �����ϼ̽��ϴ�.\n");
};


CarFactory::CarPartType BrakeSystemBuilder::selectStep(int selectedNumber,
    CarFactory::CarPartType curSelectionStep, int carPartStorage[]) {
    if ((selectedNumber >= 0 && selectedNumber <= 3) == false) {
        printf("ERROR :: ������ġ�� 1 ~ 3 ������ ���� ����\n");
        CarFactory::delay(800);
        return curSelectionStep;
    }

    if (selectedNumber == REWIND) return CarFactory::CarPartType::Engine_Q;

    buildPart(selectedNumber, carPartStorage);
    CarFactory::delay(800);
    return CarFactory::CarPartType::SteeringSystem_Q;
};

void BrakeSystemBuilder::buildPart(int selectedNumber, int carPartStorage[]) {
    carPartStorage[CarFactory::BrakeSystem_Q] = selectedNumber;
    if (selectedNumber == CarFactory::BrakeSystem::MANDO)
        printf("MANDO ������ġ�� �����ϼ̽��ϴ�.\n");
    if (selectedNumber == CarFactory::BrakeSystem::CONTINENTAL)
        printf("CONTINENTAL ������ġ�� �����ϼ̽��ϴ�.\n");
    if (selectedNumber == CarFactory::BrakeSystem::BOSCH_B)
        printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
};

CarFactory::CarPartType SteeringSystemBuilder::selectStep(int selectedNumber,
    CarFactory::CarPartType curSelectionStep, int carPartStorage[]) {
    if ((selectedNumber >= 0 && selectedNumber <= 2) == false) {
        printf("ERROR :: ������ġ�� 1 ~ 2 ������ ���� ����\n");
        CarFactory::delay(800);
        return curSelectionStep;
    }

    if (selectedNumber == REWIND) return CarFactory::CarPartType::BrakeSystem_Q;

    buildPart(selectedNumber, carPartStorage);
    CarFactory::delay(800);
    return  CarFactory::CarPartType::Run_Test;
};

void SteeringSystemBuilder::buildPart(int selectedNumber, int carPartStorage[]) {
    carPartStorage[CarFactory::SteeringSystem_Q] = selectedNumber;
    if (selectedNumber == CarFactory::SteeringSystem::BOSCH_S)
        printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
    if (selectedNumber == CarFactory::SteeringSystem::MOBIS)
        printf("MOBIS ������ġ�� �����ϼ̽��ϴ�.\n");
};