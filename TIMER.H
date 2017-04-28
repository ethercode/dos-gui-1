#ifndef _TIMER_
#define _TIMER_

#include "object.h"
#include <time.h>

class TTimer:public TObject
{
public:

    void    predefine(int num);
    void    paint();
    void    setCaption(char* newCaption);
    int     getAbsoluteX1();
    int     getAbsoluteY1();
    int     getAbsoluteX2();
    int     getAbsoluteY2();
    void    checkForEvents();
    void    reset();
    void    setFlat(int flatness);
    void    setLeft(int newLeft);
    void    setTop(int newTop);
    void    setWidth(int newWidth);
    void    setHeight(int newHeight);
    void    setInterval(int intervalTime);
    void    setEnabled(int enabledFlag);


            TTimer(TObject* parent);
            ~TTimer();
    void    onTimer();

    int     interval;
    int     enabled;

private:

    long    lastTime;
    clock_t start, end;
};

#endif
