#include "unity.h"
#include "helper.h"

void AssertEqualGH_Init_s(GH_Init_s expected, GH_Init_s actual, unsigned short line)
{
    UNITY_TEST_ASSERT_EQUAL_INT(expected.mode, actual.mode, line, "GH_Init_s.mode comparison failed.");
    UNITY_TEST_ASSERT_EQUAL_INT(expected.pin, actual.pin, line, "GH_Init_s.pin comparison failed.");
    UNITY_TEST_ASSERT_EQUAL_INT(expected.pull, actual.pull, line, "GH_Init_s.pull comparison failed.");
}