/* HAL-only entry function */
#include "hal_data.h"
void hal_entry(void)
{
    /* TODO: add your own code here */
    extern void test_ctsu(void);
    extern void test_touch(void);
    extern void test_button(void);

    initialise_monitor_handles();
    test_ctsu();
    test_touch();
    test_button();

    while(1);
}
