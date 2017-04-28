#include "window.h"
#include "mouse.h"

extern TMouse*  mouse;

void TWindow::init()
{
    x1 = 0;
    y1 = 0;
    x2 = 64;
    y2 = 64;
    root = 0;
    mouseState = MOUSE_OUTSIDE;
}

void TWindow::paint()
{
}

TWindow::TWindow()
{
    init();
}


TWindow::TWindow(TObject* parentObject)
{
    init();
    setParent(parentObject);
}


TWindow::~TWindow()
{
}

int TWindow::getX1()
{
    return x1;
}

int TWindow::getY1()
{
    return y1;
}

int TWindow::getX2()
{
    return x2;
}

int TWindow::getY2()
{
    return y2;
}

void TWindow::setLeft(int newLeft)
{
    int width   = x2 - x1;
    x1 = newLeft;
    x2 = newLeft + width;
    if (autoRedraw)
    {
        parent->paint();
    }
}

void TWindow::setWidth(int newWidth)
{
    x2 = x1 + newWidth;
    if (autoRedraw)
    {
        parent->paint();
    }
}

void TWindow::setHeight(int newHeight)
{
    y2 = y1 + newHeight;
    if (autoRedraw)
    {
        parent->paint();
    }
}

void TWindow::setTop(int newTop)
{
    int height  = y2 - y1;
    y1 = newTop;
    y2 = newTop + height;
    if (autoRedraw)
    {
        parent->paint();
    }
}

void TWindow::setX1(int newX1)
{
    if (root)
    {
        return;
    }
    x1 = newX1;
    if (!autoRedraw)
    {
        return;
    }
    parent->paint();
}

void TWindow::setY1(int newY1)
{
    if (root)
    {
        return;
    }
    y1 = newY1;
    if (!autoRedraw)
    {
        return;
    }
    parent->paint();
}

void TWindow::setX2(int newX2)
{
    if (root)
    {
        return;
    }
    x2 = newX2;
    if (!autoRedraw)
    {
        return;
    }
    parent->paint();
}

void TWindow::setY2(int newY2)
{
    if (root)
    {
        return;
    }
    y2 = newY2;
    if (!autoRedraw)
    {
        return;
    }
    parent->paint();
}

int TWindow::getAbsoluteX1()
{
    if (root)
    {
        return x1;
    }
    else
    {
        return x1 + parent->getAbsoluteX1();
    }
}

int TWindow::getAbsoluteY1()
{
    if (root)
    {
        return y1;
    }
    else
    {
        return y1 + parent->getAbsoluteY1();
    }
}

int TWindow::getAbsoluteX2()
{
    if (root)
    {
        return x2;
    }
    else
    {
        return x2 + parent->getAbsoluteX1();
    }
}

int TWindow::getAbsoluteY2()
{
    if (root)
    {
        return y2;
    }
    else
    {
        return y2 + parent->getAbsoluteY1();
    }
}

void TWindow::checkForEvents()
{
    int isInside;
    int a   = getAbsoluteX1();
    int b   = getAbsoluteY1();
    int c   = getAbsoluteX2();
    int d   = getAbsoluteY2();

    isInside = mouse->checkInside(a, b, c, d);
    if (isInside)
    {
        if (mouseState == MOUSE_ENTERED)
        {
            mouseState = MOUSE_INSIDE;
        }
        if (mouseState == MOUSE_OUTSIDE)
        {
            mouseState = MOUSE_ENTERED;
        }
    }
    else
    {
        if (mouseState == MOUSE_LEFT)
        {
            mouseState = MOUSE_OUTSIDE;
        }
        if (mouseState == MOUSE_INSIDE)
        {
            mouseState = MOUSE_LEFT;
        }
    }
    childCheckForEvents();
}

void TWindow::childCheckForEvents()
{
    int x;
    for (x = 0; x < 50; x++)
    {
        if (childAlloc[x])
        {
            child[x]->checkForEvents();
        }
    }
}

int TWindow::mouseInside()
{
    return mouse->checkInside(getAbsoluteX1(), getAbsoluteY1(), getAbsoluteX2(), getAbsoluteY2());
}

void TWindow::predefine(int num)
{
    num;
}
void TWindow::setCaption(char* newCaption)
{
    newCaption;
}
void TWindow::reset()
{
}
void TWindow::setFlat(int flatness)
{
    flatness;
}
