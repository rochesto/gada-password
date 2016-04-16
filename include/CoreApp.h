#ifndef COREAPP_H
#define COREAPP_H

#include <string>
#include "Words.h"
#include "Menu.h"

class CoreApp
{
    public:
        CoreApp();
        virtual ~CoreApp();
    protected:
    private:
        void commandSelect(std::string *);
        Menu menu;
        Words words;
};

#endif // COREAPP_H
