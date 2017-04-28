#ifndef _WINDOW_
#define _WINDOW_

#include "object.h"

class TWindow:public TObject
{
public:

                    TWindow();
                    TWindow(TObject* parent);
                    ~TWindow();

    virtual void    setFlat(int) = 0;
    virtual void    drawFlat() = 0;
    virtual void    drawUp() = 0;
    virtual void    drawDown() = 0;
    virtual void    predefine(int num);
    virtual void    setCaption(char* newCaption);
    virtual void    reset();
    virtual void killApp()
    {
    };
    virtual int mustTerminate()
    {
        return 0;
    };

    void    setLeft(int newLeft);
    void    setTop(int newTop);
    void    setWidth(int newWidth);
    void    setHeight(int newHeight);
    int     getX1();
    int     getY1();
    int     getX2();
    int     getY2();
    void    setX1(int newX1);
    void    setY1(int newY1);
    void    setX2(int newX2);
    void    setY2(int newY2);
    int     getAbsoluteX1();
    int     getAbsoluteY1();
    int     getAbsoluteX2();
    int     getAbsoluteY2();
    void    paint(void);
    void    checkForEvents();
    void    init(void);
    int     autoRedraw;
    int     mouseInside();
    virtual void setJustify(int justification)
    {
        justification;
    }

protected:

    void    childCheckForEvents();
    int     x1, y1, x2, y2;
    int     mouseState;
};



#endif
