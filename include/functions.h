#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

using namespace std;

namespace func{

    void createMofifierFile();

    void lsDir(); //List dictionaries of dictionaries folder
    void rmDic(string name = ""); // Remove dictionary
    void cls();

    void createDir(string name);
    void writeFile(string name, string text );

    void clearDict(string dict);
    void sortDict(string);

    void comcatDics(string dic1, string dic2);
}

#endif // FUNCTIONS_H
