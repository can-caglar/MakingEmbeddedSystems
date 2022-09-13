#include "unity.h"
#include "app.h"
#include "mock_system_hal.h"
#include "mock_button.h"
#include "mock_LED.h"

void test_appInitialisesHAL()
{
    //system_init_Expect();

    run_app();
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