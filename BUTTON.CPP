#include "apptags.h"
#include "button.h"
#include "mouse.h"

#include <graphics.h>
#include <string.h>

extern TMouse*  mouse;

TButton::TButton()
{
    caption = new char[100];
}

TButton::TButton(TObject* parentObject)
{
    caption = new char[100];
    setParent(parentObject);
}

TButton::~TButton()
{
    delete[] caption;
}

void TButton::drawFlat()
{
    if (!flat)
    {
        drawUp();
        return;
    }
    int a, b, c, d;
    a = getAbsoluteX1();
    b = getAbsoluteY1();
    c = getAbsoluteX2();
    d = getAbsoluteY2();
    mouse->hide();
    setfillstyle(SOLID_FILL, foregroundColour);
    bar(a, b, c, d);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    setcolor(captionColour);
    outtextxy((a + c) / 2, (b + d) / 2, caption);
    repaintChildren();
    mouse->show();
}

void TButton::drawUp()
{
    int a, b, c, d;
    a = getAbsoluteX1();
    b = getAbsoluteY1();
    c = getAbsoluteX2();
    d = getAbsoluteY2();
    mouse->hide();
    setcolor(light3d);
    line(a, b, a, d);
    line(a, b, c, b);
    setcolor(dark3d);
    line(c, d, a, d);
    line(c, d, c, b);
    setfillstyle(SOLID_FILL, foregroundColour);
    bar(a + 1, b + 1, c - 1, d - 1);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    setcolor(captionColour);
    outtextxy((a + c) / 2, (b + d) / 2, caption);
    repaintChildren();
    mouse->show();
}

void TButton::drawDown()
{
    int a, b, c, d;
    a = getAbsoluteX1();
    b = getAbsoluteY1();
    c = getAbsoluteX2();
    d = getAbsoluteY2();
    mouse->hide();
    setcolor(light3d);
    line(c, d, a, d);
    line(c, d, c, b);
    setcolor(dark3d);
    line(a, b, a, d);
    line(a, b, c, b);
    setfillstyle(SOLID_FILL, foregroundColour);
    bar(a + 1, b + 1, c - 1, d - 1);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    setcolor(captionColour);
    outtextxy((a + c) / 2 + 1, (b + d) / 2 + 1, caption);
    repaintChildren();
    mouse->show();
}

void TButton::setCaption(char* newCaption)
{
    strcpy(caption, newCaption);
    if (autoRedraw)
    {
        paint();
    }
}


void TButton::paint()
{
    autoRedraw = 1;
    if (flat)
    {
        drawFlat();
    }
    else
    {
        drawUp();
    }
}

void TButton::reset()
{
    x1 = 4;
    y1 = 16;
    x2 = 80;
    y2 = 36;
    light3d = WHITE;
    dark3d = DARKGRAY;
    foregroundColour = LIGHTGRAY;
    captionColour = BLACK;
    strcpy(caption, "button");
    flat = 1;
    autoRedraw = 0;
}

void TButton::checkForEvents()
{
    TWindow::checkForEvents();
    if (mouseState == MOUSE_ENTERED)
    {
        if (flat)
        {
            drawUp();
        }
        mayClick = 0;
    }
    if (mouseState == MOUSE_LEFT)
    {
        if (flat)
        {
            drawFlat();
        }
        else
        {
            drawUp();
        }
        mayClick = 0;
    }
    if (mouseInside())
    {
        if (mouse->leftClickState == BUTTON_DOWN)
        {
            drawDown();
            mayClick = 1;
        }
        if (mouse->leftClickState == BUTTON_UP)
        {
            drawUp();
            if (mayClick)
            {
                onClick();
            }
            mayClick = 0;
        }
    }
}

void TButton::childCheckForEvents()
{
    TWindow::childCheckForEvents();
}

void TButton::setFlat(int flatness)
{
    flat = flatness;
    if (autoRedraw)
    {
        paint();
    }
}


void TButton::onClick()
{
    onEvent(this, ONCLICK);
}

