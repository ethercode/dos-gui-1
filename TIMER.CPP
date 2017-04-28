#include "apptags.h"
#include "timer.h"
#include "time.h"
#include "object.h"

#include <stddef.h>

TTimer::TTimer(TObject* parentObject)
{
    setParent(parentObject);
    interval = 1000;
    enabled = 0;
    start = clock();
}

TTimer::~TTimer()
{
}

void TTimer::setEnabled(int enabledFlag)
{
    enabled = enabledFlag;
    lastTime = time(NULL);
}

void TTimer::setInterval(int intervalTime)
{
    interval = intervalTime;
}

void TTimer::onTimer()
{
    onEvent(this, ONTIMER);
}

void TTimer::checkForEvents()
{
    end = clock();
    if ((end - start) / CLK_TCK * 1000 >= interval)
    {
        if (enabled)
        {
            onTimer();
        }
        start = clock();
        end = start;
    }
}

void TTimer::predefine(int num)
{
    num;
}
void TTimer::paint()
{
}
void TTimer::setCaption(char* newCaption)
{
    newCaption;
}
int TTimer::getAbsoluteX1()
{
    return 0;
}
int TTimer::getAbsoluteY1()
{
    return 0;
}
int TTimer::getAbsoluteX2()
{
    return 0;
}
int TTimer::getAbsoluteY2()
{
    return 0;
}
void TTimer::reset()
{
}
void TTimer::setFlat(int flatness)
{
    flatness;
}
void TTimer::setLeft(int newLeft)
{
    newLeft;
}
void TTimer::setTop(int newTop)
{
    newTop;
}
void TTimer::setWidth(int newWidth)
{
    newWidth;
}
void TTimer::setHeight(int newHeight)
{
    newHeight;
}
