#ifndef _CHECKBOX_
#define _CHECKBOX_

#include "window.h"

class TCheckbox:public TWindow
{
public:

            TCheckbox();
            TCheckbox(TObject* parentObject);
            ~TCheckbox();
    void    paint(void);
    void    reset();
    int     isChecked(void);
    void    setChecked(int);
    void    init(void);
    void    checkForEvents();
    void    toggle();

    virtual void setFlat(int flatness)
    {
        flatness;
    };
    virtual void drawFlat()
    {
    };
    virtual void drawUp()
    {
    };
    virtual void drawDown()
    {
    };


private:

    int     checked;
    char*   caption;
    int     captionTextColour;
    int     foregroundColour;
    int     dark3d;
    int     light3d;
    int     mayClick;
};

#endif
