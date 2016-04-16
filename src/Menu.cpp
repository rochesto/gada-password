#include "Menu.h"
#include <iostream>

using namespace std;

Menu::Menu()
{

    title = "GADA password";

}

Menu::~Menu(){}

void Menu::printTitle()
{
    cout << "######################################" << endl;
    cout << "#                                    #" << endl;
    cout << "#        " << title << "                #" << endl;
    cout << "#                      by: rochesto  #" << endl;
    cout << "######################################" << endl;
}

void Menu::printMenu()
{

    cout << endl;
    cout << "Command    Description" << endl;
    cout << "=======    ===========" << endl;
    cout << endl;
    cout << "?          Help" << endl;
    cout << "command ?  Show command options" << endl;
    cout << endl;
    cout << "ls         List dictionaries" << endl;
    cout << "rm         Remove dictionary" << endl;
    cout << endl;
    cout << "new        Enter words and create a new dict" << endl;
    cout << "url        Read url and create a new dict" << endl;
    cout << "file       Read a file and create a new dict" << endl;
    cout << "brute      Generates a dictionary with all the absolutely of a given size" << endl;
    cout << endl;
    cout << "show       Show default modifiers from file modifiers.cfg" << endl;
    cout << "modifiers  Modify modifiers with nano editor" << endl;
    cout << endl;
    cout << "run        Execute modifiers"<< endl;
    cout << "size       Delete words with min and max size" << endl;
    cout << endl;
    cout << "comcat     Concat two dictionaries" << endl;
    //cout << "stats      Dictionary stats" << endl;
    cout << endl;
    cout << "version    Show version" << endl;
    //cout << "about      Show info about autor" << endl;
    cout << "exit       Close program" << endl;

}

void Menu::showHelp(int * lvls)
{

    cout << "Option     Level     Description" << endl;
    cout << "======     =====     ==========" << endl << endl;
    cout << "date        " << lvls[0] << "        Add years" << endl;
    cout << "capital     " << lvls[1] << "        Add capital letters" << endl;
    cout << "random      " << lvls[2] << "        Add ramdom numbers" << endl;
    cout << "special     " << lvls[3] << "        Add special characters" << endl;
    cout << "comcat   No level    Concat words" << endl << endl;

}

void Menu::lsHelp()
{
    header("ls  ");
    cout << endl;
    cout << "Usage: 'ls'" << endl;
    cout << "   List files from current  " << endl << endl;
}

void Menu::rmHelp()
{
    header("rm  ");
    cout << endl;
    cout << "Usage 1: 'rm'" << endl;
    cout << "   List file from current directory " << endl << endl;
    cout << "Usage 2: 'rm name'" << endl;
    cout << "   Remove file name" << endl << endl;
}

void Menu::newHelp()
{
    header("new ");
    cout << endl;
    cout << "Usage: new" << endl;
    cout << "   Enter word by word, to finish enter 'q' or 'quit'" << endl;
    cout << endl;
}

void Menu::fileHelp()
{
    header("file");
    cout << endl;
    cout << "Usage 1: 'file'" << endl;
    cout << "   COmmand line asks for name of file and then generate dictionary" << endl << endl;
    cout << "Usage 2: 'file name'" << endl;
    cout << "   Generate dictionary about all words of file" << endl << endl;
}

void Menu::urlHelp()
{
    header("url ");
    cout << endl;
    cout << "Usage 1: 'url'" << endl;
    cout << "   Command line asks for name of web page and then generate dictionary" << endl << endl;
    cout << "Usage 2: 'url http://page.html'" << endl;
    cout << "   Generate dictionary about all words of web page" << endl;
    cout << "Options: " << endl;
    cout << "   all    Read all web recusively" << endl << endl;
}

void Menu::bruteHelp()
{

    header("Brute");
    cout << endl;
    cout << "Usage: brute min max" << endl;
    cout << "   min: min lengh of words generated" << endl;
    cout << "   max: max lengh of words generated" << endl;
    cout << "Example: brute 6 9" << endl;
    cout << "Configure characters from modifiers.cfg" << endl << endl;


}

void Menu::runHelp()
{
    header("run ");
    cout << endl;
    cout << "Usage 1: 'run'" << endl;
    cout << "   run the configured switches" << endl << endl;
    cout << "Usage 2: 'run option level dictionary'" << endl;
    cout << "   Apply a single modifier" << endl;
    cout << "   Example: 'run date 2 spanish.dic'" << endl << endl;
    cout << "Options: " << endl << "    date, capital, random, special, comcat" << endl;
    cout << "Level: " << endl << "  0:Default 1:XXXword 2:wordXXX 3:XXXwordXXX 4:woXXXrd 5:XXXwoXXXrdXX" << endl << endl;

    cout << "Capital:" << endl;
    cout << "Level: " << endl << "  0:Default 1:Word 2:worD 3:WorD 4:WORD 5:Word,wOrd,woRd,worD,WORD 6:Lowercase" << endl;
    cout << "Example: run capital 3 spanish.dic" << endl << endl;

    cout << "Random:" << endl;
    cout << "Level: " << endl << "  0:Default 1:XXXword 2:wordXXX 3:XXXwordXXX 4:woXXXrd" << endl << endl;
    cout << "Example: run random 2 spanish.dic" << endl;
    cout << endl;
}

void Menu::sizeHelp()
{

    header("Size");
    cout << endl;
    cout << "Usage 1: size dictionary min max" << endl;
    cout << "   Example: size names.txt 5 20" << endl;
    cout << "Usage 2: size dictionary" << endl;
    cout << "   Read min and max from modifiers.cfg" << endl;
    cout << "min: Delete all words with size is smaller than min" << endl;
    cout << "max: Delete all words with size is biger than man" << endl;
}

void Menu::comcatHelp()
{

    header("Comcat");
    cout << endl;
    cout << "Usage: comcat dictionary1 dictionary2" << endl;
    cout << "   Example: comcat names.txt english.dic" << endl;
    cout << "Create a new dictionary with all words of both dictionaries" << endl;

}

void Menu::header(string name = "Menu")
{
    cout << "##############################" << endl;
    cout << "#          Help " <<  name <<"         #" << endl;
    cout << "##############################" << endl;
}

void Menu::version()
{
    cout << " Gada-password" << endl << "    Version: 0.1    beta" << endl;
}

void Menu::about()
{

}
