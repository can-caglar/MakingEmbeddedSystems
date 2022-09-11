#include "unity.h"

void setUp(void)
{

}

void tearDown(void)
{

}

void test_Fail(void)
{
    TEST_FAIL_MESSAGE("Failed on purpose");
}

/*
Note:

ORANGE  PD13
GREEN   PD12
BUTTON  PA0

- [ ] Input line on PA0 
- [ ] Interrupt routed to button
- [ ] Input line is debounced
- [ ] Output on PD13 when button pressed

*/