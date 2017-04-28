#ifndef _DRIVER_
#define _DRIVER_

#include "object.h"
#include "button.h"


class TDriver
{
public:

            TDriver();
            ~TDriver();
    void    init();
    void    run();
    void    end();

private:

    TObject*root;
};

#endif