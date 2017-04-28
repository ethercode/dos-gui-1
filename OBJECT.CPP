#include "object.h"
#include "apptags.h"

TObject::TObject()
{
    initialise();
}

TObject::TObject(TObject* parentObject)
{
    setParent(parentObject);
    initialise();
}

TObject::~TObject()
{
}

void TObject::setParent(TObject* newParent)
{
    parent = newParent;
    parent->addChild(this);
}

int TObject::addChild(TObject* newChild)
{
    int x           = 0;
    int allocated   = 0;
    do
    {
        if (!childAlloc[x])
        {
            child[x] = newChild;
            childAlloc[x] = 1;
            allocated = 1;
        }
        x++;
    }
    while (!allocated);
    return x - 1;
}

void TObject::removeChild(TObject* oldChild)
{
    int x   = 0;
    for (x = 0; x < 50; x++)
    {
        if ((child[x] == oldChild) && (childAlloc[x]))
        {
            childAlloc[x] = 0;
        }
    }
}

void TObject::initialise()
{
    int x;
    tag = -1;
    root = 0;
    for (x = 0; x < 50; x++)
    {
        childAlloc[x] = 0;
    }
}

void TObject::repaintChildren()
{
    int x;
    for (x = 0; x < 50; x++)
    {
        if (childAlloc[x])
        {
            child[x]->paint();
        }
    }
}

void TObject::removeChildren()
{
    int x;
    for (x = 0; x < 50; x++)
    {
        if (childAlloc[x])
        {
            delete child[x];
        }
    }
}

TObject* TObject::findRoot()
{
    TObject*dummy;
    int     found   = 0;
    dummy = this;
    while (!found)
    {
        if (!dummy->root)
        {
            dummy = dummy->parent;
        }
        else
        {
            found = 1;
        }
    }
    return dummy;
}

void TObject::onEvent(TObject* sender, int event)
{
    if (sender->tag == CHECKBOXTIMER)
    {
        findRoot()->child[1]->child[2]->toggle();
    }
    if (sender->tag == CLOSEBUTTON)
    {
        findRoot()->killApp();
    }
}








