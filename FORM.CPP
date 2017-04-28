#include "form.h"
#include "mouse.h"

#include <graphics.h>
#include <string.h>
#include <conio.h>

extern TMouse*  mouse;

TForm::TForm()
{
    caption = new char[100];
}

TForm::TForm(TObject* parentObject)
{
    caption = new char[100];
    setParent(parentObject);
}

TForm::~TForm()
{
    delete[] caption;
}

void TForm::setCaption(char* newCaption)
{
    strcpy(caption, newCaption);
    paint();
}


void TForm::paint()
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
    if (hasCaption)
    {
        setfillstyle(SOLID_FILL, captionColour);
        bar(a + 2, b + 2, c - 2, b + 13);
        setcolor(captionTextColour);
        settextjustify(LEFT_TEXT, TOP_TEXT);
        outtextxy(a + 4, b + 4, caption);
    }
    repaintChildren();
    mouse->show();
}

void TForm::predefine(int num)
{
    if (num == 0)
    {
        x1 = 64;
        y1 = 64;
        x2 = 575;
        y2 = 415;
        light3d = WHITE;
        dark3d = DARKGRAY;
        captionColour = BLUE;
        captionTextColour = WHITE;
        foregroundColour = LIGHTGRAY;
        strcpy(caption, "Form1");
        hasCaption = 1;
        canMove = 1;
    }
    if (num == 1)
    {
        x1 = 0;
        y1 = 462;
        x2 = 639;
        y2 = 479;
        light3d = WHITE;
        dark3d = DARKGRAY;
        foregroundColour = LIGHTGRAY;
        hasCaption = 0;
        canMove = 0;
    }
    parent->paint();
}

void TForm::checkForEvents()
{
    TWindow::checkForEvents();
    if ((mouse->leftClickState == BUTTON_DOWN) && (mouse->checkInside(getAbsoluteX1() + 2, getAbsoluteY1() + 2, getAbsoluteX2() - 15, getAbsoluteY1() + 13)) && canMove)
    {
        int apply   = 1;
        int xOld, yOld;
        int omx, omy;
        xOld = mouse->x;
        yOld = mouse->y;
        int newX1, newY1, newX2, newY2;
        int xDiff, yDiff;
        autoRedraw = 0;
        drawChangeBox(x1, y1, x2, y2);
        xDiff = xOld - mouse->x;
        yDiff = yOld - mouse->y;
        while (mouse->leftDown == 1)
        {
            if (kbhit())
            {
                int pressed = getch();
                if (pressed == 0)
                {
                    getch();
                }
                apply = 0;
                drawChangeBox(x1 + xDiff, y1 + yDiff, x2 + xDiff, y2 + yDiff);
                break;
            }
            omx = mouse->x;
            omy = mouse->y;
            mouse->update();
            if ((omx != mouse->x) || (omy != mouse->y))
            {
                mouse->hide();
                drawChangeBox(x1 + xDiff, y1 + yDiff, x2 + xDiff, y2 + yDiff);
                xDiff = mouse->x - xOld;
                yDiff = mouse->y - yOld;
                drawChangeBox(x1 + xDiff, y1 + yDiff, x2 + xDiff, y2 + yDiff);
                mouse->show();
            }
        }
        xDiff = xOld - mouse->x;
        yDiff = yOld - mouse->y;
        newX1 = getX1() - xDiff;
        newY1 = getY1() - yDiff;
        newX2 = getX2() - xDiff;
        newY2 = getY2() - yDiff;
        if (newX1 < 0)
        {
            newX2 -= newX1;
            newX1 = 0;
        }
        if (newY1 < 0)
        {
            newY2 -= newY1;
            newY1 = 0;
        }
        if (apply)
        {
            x1 = newX1;
            y1 = newY1;
            x2 = newX2;
            y2 = newY2;
            if (xDiff || yDiff)
            {
                parent->paint();
            }
        }
    }
}

void TForm::childCheckForEvents()
{
    TWindow::childCheckForEvents();
}

void TForm::drawChangeBox(int x1, int y1, int x2, int y2)
{
    int loop;
    for (loop = x1; loop <= x2; loop += 2)
    {
        putpixel(loop, y1, 16 - getpixel(loop, y1));
    }
    for (loop = x1; loop <= x2; loop += 2)
    {
        putpixel(loop, y2, 16 - getpixel(loop, y2));
    }
    for (loop = y1; loop <= y2; loop += 2)
    {
        putpixel(x1, loop, 16 - getpixel(x1, loop));
    }
    for (loop = y1; loop <= y2; loop += 2)
    {
        putpixel(x2, loop, 16 - getpixel(x2, loop));
    }
}

void TForm::drawDown()
{
};
void TForm::drawUp()
{
};
void TForm::drawFlat()
{
};
void TForm::reset()
{
};
void TForm::setFlat(int flatness)
{
    flatness;
};

