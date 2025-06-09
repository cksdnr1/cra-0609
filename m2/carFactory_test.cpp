#include "gmock/gmock.h"
#include "carFactory.hpp"

#include <gtest/gtest.h>
using namespace testing;

TEST(selectCarType0, TC1) {
	CarFactory carFactory;
	CarFactory::CarPartType curType = CarFactory::CarPartType::CarType_Q;
	curType = carFactory.makePartOfCar(0, curType);
	EXPECT_EQ(curType, CarFactory::CarPartType::CarType_Q);
}

TEST(selectCarType1, TC1) {
	CarFactory carFactory;
	CarFactory::CarPartType curType = CarFactory::CarPartType::CarType_Q;
	curType = carFactory.makePartOfCar(1, curType);
	EXPECT_EQ(curType, CarFactory::CarPartType::Engine_Q);
}

TEST(selectCarType2, TC1) {
	CarFactory carFactory;
	CarFactory::CarPartType curType = CarFactory::CarPartType::CarType_Q;
	curType = carFactory.makePartOfCar(2, curType);
	EXPECT_EQ(curType, CarFactory::CarPartType::Engine_Q);
}

TEST(selectCarType3, TC1) {
	CarFactory carFactory;
	CarFactory::CarPartType curType = CarFactory::CarPartType::CarType_Q;
	curType = carFactory.makePartOfCar(3, curType);
	EXPECT_EQ(curType, CarFactory::CarPartType::Engine_Q);
}

TEST(selectEngine0, TC1) {
	CarFactory carFactory;
	CarFactory::CarPartType curType = CarFactory::CarPartType::Engine_Q;
	curType = carFactory.makePartOfCar(0, curType);
	EXPECT_EQ(curType, CarFactory::CarPartType::CarType_Q);
}

TEST(selectEngine1, TC1) {
	CarFactory carFactory;
	CarFactory::CarPartType curType = CarFactory::CarPartType::Engine_Q;
	curType = carFactory.makePartOfCar(1, curType);
	EXPECT_EQ(curType, CarFactory::CarPartType::BrakeSystem_Q);
}

TEST(selectEngine2, TC1) {
	CarFactory carFactory;
	CarFactory::CarPartType curType = CarFactory::CarPartType::Engine_Q;
	curType = carFactory.makePartOfCar(2, curType);
	EXPECT_EQ(curType, CarFactory::CarPartType::BrakeSystem_Q);
}

TEST(selectEngine3, TC1) {
	CarFactory carFactory;
	CarFactory::CarPartType curType = CarFactory::CarPartType::Engine_Q;
	curType = carFactory.makePartOfCar(3, curType);
	EXPECT_EQ(curType, CarFactory::CarPartType::BrakeSystem_Q);
}

TEST(selectEngine4, TC1) {
	CarFactory carFactory;
	CarFactory::CarPartType curType = CarFactory::CarPartType::Engine_Q;
	curType = carFactory.makePartOfCar(4, curType);
	EXPECT_EQ(curType, CarFactory::CarPartType::BrakeSystem_Q);
}

TEST(selectEngine5, TC1) {
	CarFactory carFactory;
	CarFactory::CarPartType curType = CarFactory::CarPartType::Engine_Q;
	curType = carFactory.makePartOfCar(5, curType);
	EXPECT_EQ(curType, CarFactory::CarPartType::Engine_Q);
}

TEST(selectBrakeSystem0, TC1) {
	CarFactory carFactory;
	CarFactory::CarPartType curType = CarFactory::CarPartType::BrakeSystem_Q;
	curType = carFactory.makePartOfCar(0, curType);
	EXPECT_EQ(curType, CarFactory::CarPartType::Engine_Q);
}

TEST(selectBrakeSystem1, TC1) {
	CarFactory carFactory;
	CarFactory::CarPartType curType = CarFactory::CarPartType::BrakeSystem_Q;
	curType = carFactory.makePartOfCar(1, curType);
	EXPECT_EQ(curType, CarFactory::CarPartType::SteeringSystem_Q);
}

TEST(selectBrakeSystem2, TC1) {
	CarFactory carFactory;
	CarFactory::CarPartType curType = CarFactory::CarPartType::BrakeSystem_Q;
	curType = carFactory.makePartOfCar(2, curType);
	EXPECT_EQ(curType, CarFactory::CarPartType::SteeringSystem_Q);
}

TEST(selectBrakeSystem3, TC1) {
	CarFactory carFactory;
	CarFactory::CarPartType curType = CarFactory::CarPartType::BrakeSystem_Q;
	curType = carFactory.makePartOfCar(3, curType);
	EXPECT_EQ(curType, CarFactory::CarPartType::SteeringSystem_Q);
}

TEST(selectBrakeSystem4, TC1) {
	CarFactory carFactory;
	CarFactory::CarPartType curType = CarFactory::CarPartType::BrakeSystem_Q;
	curType = carFactory.makePartOfCar(4, curType);
	EXPECT_EQ(curType, CarFactory::CarPartType::BrakeSystem_Q);
}

TEST(selectSteeringSystem0, TC1) {
	CarFactory carFactory;
	CarFactory::CarPartType curType = CarFactory::CarPartType::SteeringSystem_Q;
	curType = carFactory.makePartOfCar(0, curType);
	EXPECT_EQ(curType, CarFactory::CarPartType::BrakeSystem_Q);
}

TEST(selectSteeringSystem1, TC1) {
	CarFactory carFactory;
	CarFactory::CarPartType curType = CarFactory::CarPartType::SteeringSystem_Q;
	curType = carFactory.makePartOfCar(1, curType);
	EXPECT_EQ(curType, CarFactory::CarPartType::Run_Test);
}

TEST(selectSteeringSystem2, TC1) {
	CarFactory carFactory;
	CarFactory::CarPartType curType = CarFactory::CarPartType::SteeringSystem_Q;
	curType = carFactory.makePartOfCar(2, curType);
	EXPECT_EQ(curType, CarFactory::CarPartType::Run_Test);
}

TEST(selectSteeringSystem3, TC1) {
	CarFactory carFactory;
	CarFactory::CarPartType curType = CarFactory::CarPartType::SteeringSystem_Q;
	curType = carFactory.makePartOfCar(3, curType);
	EXPECT_EQ(curType, CarFactory::CarPartType::SteeringSystem_Q);
}


TEST(selectRunAndTest0, TC1) {
	CarFactory carFactory;
	CarFactory::CarPartType curType = CarFactory::CarPartType::Run_Test;
	curType = carFactory.makePartOfCar(0, curType);
	EXPECT_EQ(curType, CarFactory::CarPartType::CarType_Q);
}

TEST(selectRunAndTest1, TC1) {
	CarFactory carFactory;
	CarFactory::CarPartType curType = CarFactory::CarPartType::Run_Test;
	curType = carFactory.makePartOfCar(1, curType);
	EXPECT_EQ(curType, CarFactory::CarPartType::Run_Test);
}

TEST(selectRunAndTest2, TC1) {
	CarFactory carFactory;
	CarFactory::CarPartType curType = CarFactory::CarPartType::Run_Test;
	curType = carFactory.makePartOfCar(2, curType);
	EXPECT_EQ(curType, CarFactory::CarPartType::Run_Test);
}

TEST(selectRunAndTest3, TC1) {
	CarFactory carFactory;
	CarFactory::CarPartType curType = CarFactory::CarPartType::Run_Test;
	curType = carFactory.makePartOfCar(3, curType);
	EXPECT_EQ(curType, CarFactory::CarPartType::Run_Test);
}

TEST(errorHandling1, TC1) {
	CarFactory carFactory;
	CarFactory::CarPartType curType = CarFactory::CarPartType::EMPTY_Q;
	curType = carFactory.makePartOfCar(0, curType);
	EXPECT_EQ(curType, CarFactory::CarPartType::CarType_Q);
}


TEST(AllTestOnceTestedForAllCoverageIsCoverdeCheck, TC1) {
	for (int car_type = static_cast<int>(CarFactory::CarType::SEDAN); car_type < static_cast<int>(CarFactory::CarType::EMPTY_C); car_type++) {
		for (int engine_type = static_cast<int>(CarFactory::Engine::GM); engine_type < static_cast<int>(CarFactory::Engine::EMPTY_E); engine_type++) {
			for (int brake_type = static_cast<int>(CarFactory::BrakeSystem::MANDO); brake_type < static_cast<int>(CarFactory::BrakeSystem::EMPTY_B); brake_type++) {
				for (int steering_type = static_cast<int>(CarFactory::SteeringSystem::BOSCH_S); steering_type < static_cast<int>(CarFactory::SteeringSystem::EMPTY_S); steering_type++) {
					for (int run_and_test_type = static_cast<int>(CarFactory::RunAndTest::RUN); run_and_test_type < static_cast<int>(CarFactory::RunAndTest::EMPTY_R); run_and_test_type++) {
						CarFactory carFactory;
						carFactory.makePartOfCar(car_type, CarFactory::CarPartType::CarType_Q);
						carFactory.makePartOfCar(engine_type, CarFactory::CarPartType::Engine_Q);
						carFactory.makePartOfCar(brake_type, CarFactory::CarPartType::BrakeSystem_Q);
						carFactory.makePartOfCar(steering_type, CarFactory::CarPartType::SteeringSystem_Q);
						carFactory.makePartOfCar(run_and_test_type, CarFactory::CarPartType::Run_Test);
					}
				}
			}
		}
	}
}