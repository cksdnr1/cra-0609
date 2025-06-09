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
        printf("자동차가 동작되지 않습니다\n");
        return;
    }

    if (carPartStorage[Engine_Q] == Engine::InvalidEngine)
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
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Sedan에는 Continental제동장치 사용 불가\n");
    }
    else if (carPartStorage[CarType_Q] == SUV && carPartStorage[Engine_Q] == TOYOTA)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("SUV에는 TOYOTA엔진 사용 불가\n");
    }
    else if (carPartStorage[CarType_Q] == TRUCK && carPartStorage[Engine_Q] == WIA)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Truck에는 WIA엔진 사용 불가\n");
    }
    else if (carPartStorage[CarType_Q] == TRUCK && carPartStorage[BrakeSystem_Q] == MANDO)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Truck에는 Mando제동장치 사용 불가\n");
    }
    else if (carPartStorage[BrakeSystem_Q] == BOSCH_B && carPartStorage[SteeringSystem_Q] != BOSCH_S)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Bosch엔진에는 Bosch조향장치 이외 사용 불가\n");
    }
    else
    {
        printf("자동차 부품 조합 테스트 결과 : PASS\n");
    }
}

CarFactory::CarPartType CarTypeBuilder::selectStep(int selectedNumber,
    CarFactory::CarPartType curSelectionStep, int carPartStorage[]) {
    if ((selectedNumber >= 1 && selectedNumber <= 3) == false) {
        printf("ERROR :: 차량 타입은 1 ~ 3 범위만 선택 가능\n");
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
        printf("차량 타입으로 Sedan을 선택하셨습니다.\n");
    if (selectedNumber == CarFactory::CarType::SUV)
        printf("차량 타입으로 SUV을 선택하셨습니다.\n");
    if (selectedNumber == CarFactory::CarType::TRUCK)
        printf("차량 타입으로 Truck을 선택하셨습니다.\n");
};

CarFactory::CarPartType EngineTypeBuilder::selectStep(int selectedNumber,
    CarFactory::CarPartType curSelectionStep, int carPartStorage[]) {
    if ((selectedNumber >= 0 && selectedNumber <= 4) == false) {
        printf("ERROR :: 엔진은 1 ~ 4 범위만 선택 가능\n");
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
        printf("GM 엔진을 선택하셨습니다.\n");
    if (selectedNumber == CarFactory::Engine::TOYOTA)
        printf("TOYOTA 엔진을 선택하셨습니다.\n");
    if (selectedNumber == CarFactory::Engine::WIA)
        printf("WIA 엔진을 선택하셨습니다.\n");
};


CarFactory::CarPartType BrakeSystemBuilder::selectStep(int selectedNumber,
    CarFactory::CarPartType curSelectionStep, int carPartStorage[]) {
    if ((selectedNumber >= 0 && selectedNumber <= 3) == false) {
        printf("ERROR :: 제동장치는 1 ~ 3 범위만 선택 가능\n");
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
        printf("MANDO 제동장치를 선택하셨습니다.\n");
    if (selectedNumber == CarFactory::BrakeSystem::CONTINENTAL)
        printf("CONTINENTAL 제동장치를 선택하셨습니다.\n");
    if (selectedNumber == CarFactory::BrakeSystem::BOSCH_B)
        printf("BOSCH 제동장치를 선택하셨습니다.\n");
};

CarFactory::CarPartType SteeringSystemBuilder::selectStep(int selectedNumber,
    CarFactory::CarPartType curSelectionStep, int carPartStorage[]) {
    if ((selectedNumber >= 0 && selectedNumber <= 2) == false) {
        printf("ERROR :: 조향장치는 1 ~ 2 범위만 선택 가능\n");
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
        printf("BOSCH 조향장치를 선택하셨습니다.\n");
    if (selectedNumber == CarFactory::SteeringSystem::MOBIS)
        printf("MOBIS 조향장치를 선택하셨습니다.\n");
};