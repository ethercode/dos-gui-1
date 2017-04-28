#include "driver.h"
#include "mouse.h"

TMouse* mouse;
TObject*root;

int main(void)
{
    TDriver*driver;
    driver = new TDriver;
    driver->init();
    driver->run();
    driver->end();
    delete driver;
    return 0;
}

