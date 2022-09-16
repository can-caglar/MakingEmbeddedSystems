#include "src/controller.h"

int main(void)
{
    run_controller();

    while(1)
    {
        volatile int a = 1;  // just for setting breakpoints.
    }
}
