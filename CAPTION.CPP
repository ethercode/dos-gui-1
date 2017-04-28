#include "caption.h"

#include <string.h>
#include <graphics.h>

extern TMouse*  mouse;

TCaption::TCaption(TObject* parentObject)
{
    setParent(parentObject);
    caption = new char[100];
    strcpy(caption, "caption");
}

TCaption::~TCaption()
{
    delete[] caption;
}

void TCaption::setCaption(char* newCaption)
{
    strcpy(caption, newCaption);
    if (autoRedraw)
    {
        paint();
    }
}

void TCaption::setJustify(int justification)
{
    justify = justification;
    if (autoRedraw)
    {
        paint();
    }
}

void TCaption::paint()
{
    mouse->hide();
    int a   = getAbsoluteX1();
    int b   = getAbsoluteY1();
    int c   = getAbsoluteX2();
    int d   = getAbsoluteY2();
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(a, b, c, d);
    setcolor(BLACK);
    if (justify == LEFTALIGNED)
    {
        settextjustify(LEFT_TEXT, TOP_TEXT);
        outtextxy(a + 3, b + 3, caption);
    }
    if (justify == CENTERED)
    {
        settextjustify(LEFT_TEXT, CENTER_TEXT);
        outtextxy((a + c / 2) + 3, b + 3, caption);
    }
    if (justify == RIGHTALIGNED)
    {
        settextjustify(LEFT_TEXT, RIGHT_TEXT);
        outtextxy(c - 3, b + 3, caption);
    }
    mouse->show();
}

void TCaption::predefine(int num)
{
    num;
}
void TCaption::setFlat(int flatness)
{
    flatness;
}
void TCaption::drawFlat()
{
}
void TCaption::drawUp()
{
}
void TCaption::drawDown()
{
}
void TCaption::reset()
{
}
void TCaption::setInterval(int intervalTime)
{
    intervalTime;
}
void TCaption::setEnabled(int enabledFlag)
{
    enabledFlag;
}
void TCaption::checkForEvents()
{
};

