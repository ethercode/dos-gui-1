#include "checkbox.h"
#include "mouse.h"

#include <graphics.h>
#include <string.h>

extern TMouse*  mouse;

TCheckbox::TCheckbox()
{
    init();
}

TCheckbox::TCheckbox(TObject* parentObject)
{
    setParent(parentObject);
    init();
}

TCheckbox::~TCheckbox()
{
    delete[] caption;
}

void TCheckbox::init()
{
    caption = new char[100];
}

void TCheckbox::paint(void)
{
    int a, b, c, d;
    a = getAbsoluteX1();
    b = getAbsoluteY1();
    c = getAbsoluteX2();
    d = getAbsoluteY2();
    mouse->hide();
    autoRedraw = 1;
    setcolor(light3d);
    line(a + 10, b + 10, a, b + 10);
    line(a + 10, b + 10, a + 10, b);
    setcolor(dark3d);
    line(a, b, a, b + 10);
    line(a, b, a + 10, b);
    setfillstyle(SOLID_FILL, foregroundColour);
    bar(a + 1, b + 1, a + 9, b + 9);
    bar(a, b + 11, c, d);
    if (checked)
    {
        setfillstyle(SOLID_FILL, BLACK);
        bar(a + 3, b + 3, a + 7, b + 7);
    }
    setcolor(captionTextColour);
    settextjustify(LEFT_TEXT, TOP_TEXT);
    outtextxy(a + 17, b + 2, caption);
    repaintChildren();
    mouse->show();
}

void TCheckbox::reset()
{
    mayClick = 0;
    light3d = WHITE;
    dark3d = DARKGRAY;
    captionTextColour = BLACK;
    foregroundColour = LIGHTGRAY;
    strcpy(caption, "checkbox");
    autoRedraw = 0;
    checked = 1;
    setTop(3);
    setLeft(3);
    setWidth(100);
    setHeight(12);
}

int TCheckbox::isChecked(void)
{
    return checked;
}

void TCheckbox::setChecked(int newChecked)
{
    checked = newChecked;
    paint();
}

void TCheckbox::checkForEvents(void)
{
    int checkChanged    = 0;
    TWindow::checkForEvents();
    if (mouseState == MOUSE_ENTERED)
    {
        mayClick = 0;
    }
    if ((mouseState == MOUSE_LEFT) && (mayClick))
    {
        mayClick = 0;
    }
    if (mouseInside())
    {
        if (mouse->leftClickState == BUTTON_DOWN)
        {
            checked = 1 - checked;
            mayClick = 1;
            checkChanged = 1;
        }
    }
    else
    {
        if ((mouse->leftClickState == BUTTON_UP) && mayClick)
        {
            checked = 1 - checked;
            mayClick = 0;
            checkChanged = 1;
        }
    }
    if (checkChanged)
    {
        paint();
    }
}

void TCheckbox::toggle()
{
    checked = 1 - checked;
    paint();
}
