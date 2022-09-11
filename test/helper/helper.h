#ifndef HELPER_H
#define HELPER_H

#include "gpio_hal.h"

void AssertEqualGH_Init_s(GH_Init_s expected, GH_Init_s actual, unsigned short line);

#define UNITY_TEST_ASSERT_EQUAL_GH_Init_s(expected, actual, line, message) AssertEqualGH_Init_s(expected, actual, line)

#endif