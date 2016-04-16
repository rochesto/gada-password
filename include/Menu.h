#ifndef MENU_H
#define MENU_H

#include <string>

class Menu
{
    public:
        Menu();
        virtual ~Menu();
        void printTitle();
        void printMenu();
        void showHelp(int * lvls);
        void lsHelp();
        void rmHelp();
        void newHelp();
        void fileHelp();
        void urlHelp();
        void bruteHelp();
        void runHelp();
        void sizeHelp();
        void comcatHelp();
        void header(std::string name);

        void version();
        void about();

        //Variables
        std::string title;
    protected:
    private:
};

#endif // MENU_H
