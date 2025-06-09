#include "gmock/gmock.h"
#include "carFactory.hpp"


int main() {
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}

/*
int main() {
	CarFactory carFactory;
	carFactory.makeCar();
}
*/