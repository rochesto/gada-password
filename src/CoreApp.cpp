#include "CoreApp.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include "input.h"
#include "Menu.h"
#include "functions.h"
#include "Run.h"
#include "config.h"


using namespace std;

CoreApp::CoreApp()
{

    menu.printTitle();
    menu.printMenu();
    string *com;
    input in;

    //Loop
    do
    {
        com = in.readCommand();
        commandSelect(com);

    }while(true);
}

CoreApp::~CoreApp()
{
    //dtor
}

void CoreApp::commandSelect(std::string *command)
{
    Menu menu;
    string *op = command;

    if(op[0] == "ls"){
        if (op[1] == "?")
        {
            menu.lsHelp();
        }
        else
        {
            func::lsDir();
        }
    }
    else if(op[0] == "rm"){
        if (op[1] == "?"){ menu.rmHelp(); }
        else if (op[1] != "") { func::rmDic(op[1]); }
        else{ func::rmDic(); }
    }
    else if(op[0] == "new"){
        if (op[1] == "?") { menu.newHelp(); }
        else { words.readWords(); }
    }
    else if(op[0] == "file"){
        if (op[1] == "?") { menu.fileHelp(); }
        else if (op[1] != "") { words.readFile(op[1]); }
        else if (op[1] == "") { words.readFile(); }
    }
    else if(op[0] == "url"){
        if (op[1] == "?") { menu.urlHelp(); }
        else if (op[1] != "") {

            if (op[2] == "all"){
                words.readUrl(op[1], op[2]);
            }
            else{
                words.readUrl(op[1]);
            }
        }
        else if (op[1] == "") { words.readUrl(); }
    }
    else if(op[0] == "brute")
    {
        if (op[1] == "?") menu.bruteHelp();
        else if(op[1] != "" and op[2] != "")
        {
            unsigned int minCharac = atoi(op[1].c_str());
            unsigned int maxCharac = atoi(op[2].c_str());

            Config config("modifiers.cfg");
            string dataBrute = config.pString("brute");

            if(minCharac > maxCharac)
            {
                unsigned int aux = maxCharac;
                maxCharac = minCharac;
                minCharac = aux;
            }

            string dictionary;
            cout << "Name dictionary: ";
            cin >> dictionary;

            if(minCharac == maxCharac)
            {
                words.brute(dictionary, dataBrute, minCharac);
            }
            else
            {
                for (unsigned int i = minCharac; i <= maxCharac; i++)
                {
                    words.brute(dictionary, dataBrute, i);
                }
            }
        }
        else
        {
            menu.bruteHelp();
        }



    }
    else if(op[0] == "modifiers")
    {
        system("nano modifiers.cfg");
    }
    else if(op[0] == "show"){

        int levels[5];
        int contador = 0;

        Config config("modifiers.cfg");

        map<string, Config*> messages = config.getGroups(); // all groups
        const string messagePrefix = "mod"; // prefix for group name

        for (map<string, Config*>::iterator i = messages.begin(); i != messages.end(); ++i) {
            string groupName = i->first;
            Config* group = i->second;

            if (groupName.substr(0, messagePrefix.length()) == messagePrefix) {
                levels[contador] = group->pInt("level");
                contador++;
            }
        }

        menu.showHelp(levels);
    }
    else if(op[0] == "run"){
        if (op[1] == "?") { menu.runHelp(); }
        else if (op[1] == ""){ Run run; run.multiRun(); }
        else
        {
            if (op[1] == "comcat") //Asing 1 to comcat lvl, because it don't use lvl
            {
                if(op[2] == "" or op[2] == "\n")
                {
                    string dictionary;
                    func::lsDir();
                    cout << "Dictionary to modify: ";
                    cin >> dictionary;
                    cout << dictionary << endl;
                    Run run;
                    run.runMods(op[1], dictionary, 0);
                }
                else
                {
                    Run run;
                    run.runMods(op[1], op[2], 0);
                }

            }
            else if (op[1] == "date" || op[1] == "capital" || op[1] == "random" || op[1] == "special")
            {
                int lvl = atoi(op[2].c_str());

                if (lvl >= 0 && lvl <= 6)
                {
                    if(op[3] == "" or op[3] == "\n")
                    {
                        string dictionary;
                        func::lsDir();
                        cout << "Dictionary to modify: ";
                        cin >> dictionary;
                        Run run;
                        run.runMods(op[1], dictionary, lvl);
                    }
                    else
                    {
                        Run run;
                        run.runMods(op[1], op[3], lvl);
                    }
                }
                else
                {
                    menu.runHelp();
                }
            }
            else
            {
                menu.runHelp();
            }
        }
    }

    else if (op[0] == "size")
    {
        if (op[1] == "?") { menu.sizeHelp(); }
        else
        {
            unsigned int minCharac = atoi(op[2].c_str());
            unsigned int maxCharac = atoi(op[3].c_str());
            if (minCharac == 0 and maxCharac == 0)
            {
                Config config("modifiers.cfg");
                minCharac = config.pInt("min");
                maxCharac = config.pInt("max");
            }

            if(minCharac > maxCharac)
            {
                unsigned int aux = maxCharac;
                maxCharac = minCharac;
                minCharac = aux;
            }

            Run run;
            run.deleteLimitCharacters(op[1], minCharac, maxCharac);
        }

    }

    else if (op[0] == "comcat")
    {
        if (op[1] == "?")
        {
            menu.comcatHelp();
        }
        else
        {
            func::comcatDics(op[1], op[2]);
        }

    }

    else if (op[0] == "brute")
    {
        if (op[1] == "?")
        {
            menu.sizeHelp();
        }
        else
        {
            int lvl = atoi(op[1].c_str());
            if (lvl > 0 and lvl < 30)
            {
                Run run;
                //run.brute(lvl);
            }

        }

    }

    else if(op[0] == "version"){
        menu.version();
    }
    else if (op[0] == "about"){
        menu.about();
    }
    else if (op[0] == "exit"){
        exit(EXIT_SUCCESS);
    }
    else if(op[0] == "?" or op[0] == "-h" or op[0] == "help"){
        func::cls();
        menu.printMenu();
    }
    else if(op[0] == "\n" or op[0] == "")
    {}
    else
    {
        cout << "Commad not found!" << endl;
    }

}
