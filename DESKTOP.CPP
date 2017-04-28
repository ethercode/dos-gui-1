#include "desktop.h"
#include <graphics.h>

#include "mouse.h"
#include "desktop.h"
#include "object.h"

extern TMouse*  mouse;

TDesktop::TDesktop()
{
    TWindow::root = 1;
    x1 = 0;
    y1 = 0;
    x2 = 639;
    y2 = 479;
    fillStyle = SOLID_FILL;
    fillColour = CYAN;
    terminate = 0;
    paint();
}

TDesktop::~TDesktop()
{
    terminate = 0;
}

void TDesktop::paint()
{
    mouse->hide();
    setfillstyle(fillStyle, fillColour);
    bar(x1, y1, x2, y2);
    repaintChildren();
    mouse->show();
}

void TDesktop::killApp()
{
    terminate = 1;
}

int TDesktop::mustTerminate()
{
    return terminate;
}

void TDesktop::drawFlat()
{
}
void TDesktop::drawUp()
{
}
void TDesktop::drawDown()
{
}
void TDesktop::predefine(int num)
{
    num;
}
void TDesktop::setCaption(char* newCaption)
{
    newCaption;
}
void TDesktop::reset()
{
}
void TDesktop::setFlat(int flatness)
{
    flatness;
}
