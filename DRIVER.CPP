#include "apptags.h"
#include "driver.h"
#include "mouse.h"
#include "desktop.h"
#include "form.h"
#include "button.h"
#include "checkbox.h"
#include "caption.h"
#include "timer.h"

#include <conio.h>
#include <graphics.h>

extern TMouse*  mouse;

TDriver::TDriver()
{
    int grDriver =  VGA, grMode = VGAHI;
    initgraph(&grDriver, &grMode, "");
    mouse = new TMouse;
    mouse->show();
}

TDriver::~TDriver()
{
    mouse->hide();
    delete mouse;
    closegraph();
}

void TDriver::init()
{
    TObject*startBar;
    TObject*mainWindow;
    TObject*standardButton;
    TObject*flatButton;
    TObject*myCheckbox;
    TObject*timer;
    TObject*closeButton;
    TObject*caption;

    root = new TDesktop;
    startBar = new TForm(root);
    startBar->predefine(1);
    mainWindow = new TForm(root);
    mainWindow->predefine(0);
    mainWindow->setCaption("Main window - \"Draconis\" by T.L. Murray [controls DEMO]");
    standardButton = new TButton(mainWindow);
    standardButton->reset();
    standardButton->setCaption("Standard Button");
    standardButton->setFlat(0);
    standardButton->setTop(20);
    standardButton->setLeft(10);
    standardButton->setWidth(150);
    standardButton->paint();
    flatButton = new TButton(mainWindow);
    flatButton->reset();
    flatButton->setCaption("Flat Button");
    flatButton->setFlat(1);
    flatButton->setLeft(10);
    flatButton->setTop(50);
    flatButton->setWidth(150);
    flatButton->paint();
    myCheckbox = new TCheckbox(mainWindow);
    myCheckbox->reset();
    myCheckbox->setLeft(10);
    myCheckbox->setTop(85);
    myCheckbox->paint();
    myCheckbox->tag = 1;
    closeButton = new TButton(mainWindow);
    closeButton->reset();
    closeButton->tag = CLOSEBUTTON;
    closeButton->setLeft(mainWindow->getX2() - mainWindow->getX1() - 11);
    closeButton->setTop(4);
    closeButton->setWidth(8);
    closeButton->setHeight(8);
    closeButton->setCaption("x");
    closeButton->setFlat(0);
    closeButton->paint();
    timer = new TTimer(mainWindow);
    timer->setEnabled(1);
    timer->tag = CHECKBOXTIMER;
    caption = new TCaption(mainWindow);
    caption->setLeft(10);
    caption->setTop(120);
    caption->setWidth(150);
    caption->setHeight(20);
    caption->setJustify(LEFTALIGNED);
    caption->setCaption("Sample caption");
    caption->paint();
}

void TDriver::run()
{
    int mustExit    = 0;
    while (!mustExit)
    {
        mouse->update();
        if ((mouse->leftDown == 1) && (mouse->oldLeftDown == 0))
        {
            mouse->leftClickState = BUTTON_DOWN;
        }
        if ((mouse->leftDown == 0) && (mouse->oldLeftDown == 1))
        {
            mouse->leftClickState = BUTTON_UP;
        }
        if ((mouse->leftDown == 1) && (mouse->oldLeftDown == 1))
        {
            mouse->leftClickState = BUTTON_STILL_DOWN;
        }
        if ((mouse->leftDown == 0) && (mouse->oldLeftDown == 0))
        {
            mouse->leftClickState = BUTTON_STILL_UP;
        }
        root->checkForEvents();
        mustExit = root->mustTerminate();
    }
}

void TDriver::end()
{
    delete root;
}


