#ifndef _OBJECT_
#define _OBJECT_

#include "mouse.h"

class TObject
{
public:

    void    onEvent(TObject* sender, int event);

    virtual void killApp()
    {
    };
    virtual int mustTerminate()
    {
        return 0;
    };
    virtual void    predefine(int num) = 0;
    virtual void    paint() = 0;
    virtual void    setCaption(char* newCaption) = 0;
    virtual int     getAbsoluteX1() = 0;
    virtual int     getAbsoluteY1() = 0;
    virtual int     getAbsoluteX2() = 0;
    virtual int     getAbsoluteY2() = 0;
    virtual void    checkForEvents() = 0;
    virtual void    reset() = 0;
    virtual void    setFlat(int flatness) = 0;
    virtual void    setLeft(int newLeft) = 0;
    virtual void    setTop(int newTop) = 0;
    virtual void    setWidth(int newWidth) = 0;
    virtual void    setHeight(int newHeight) = 0;
    virtual int isChecked()
    {
        return 0;
    };
    virtual void toggle()
    {
    };
    virtual void setEnabled(int x)
    {
        x;
    };
    virtual void setInterval(int x)
    {
        x;
    };
    virtual int getX1()
    {
        return 0;
    }
    virtual int getY1()
    {
        return 0;
    }
    virtual int getX2()
    {
        return 0;
    }
    virtual int getY2()
    {
        return 0;
    }
    virtual void setJustify(int justification)
    {
        justification;
    }

            TObject();
            TObject(TObject* parentObject);
            ~TObject();
    void    setParent(TObject* parent);
    int     addChild(TObject* newChild);
    void    removeChild(TObject* oldChild);
    void    initialise();
    void    removeChildren();
    TObject*findRoot(void);
    int     tag;
    TObject*parent;
    TObject*child[50];
    int     childAlloc[50];
    int     root;

protected:

    void    repaintChildren();
};

#endif

