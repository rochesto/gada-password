#include "Run.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "functions.h"
#include "config.h"

#include <sstream>

using namespace std;

Run::Run()
{
    //ctor
}

Run::~Run()
{
    //dtor
}

void Run::multiRun(){

    cout << "Building APP...." << "Not jet!!!"<< endl;


}

void Run::runMods(string modifier, string file, int lvl){

    if (modifier == "date" or modifier == "special")
    {
        modListsWords(file, modifier, lvl);
    }
    else if(modifier == "capital")
    {
        modCapital(file, lvl);
    }
    else if(modifier == "random")
    {
        modRandom(file, lvl);
    }
    else if(modifier == "comcat")
    {
        modComcat(file);
    }
}

void Run::modListsWords(string file, string modifier, int lvl)
{
    // Read file
    fstream f;
    f.open(file.c_str(), fstream::in | fstream::out | fstream::app);
    string line;
    if(f.is_open())
    {

        string newDict;
        do
        {
            cout << ("Name new dictionary: ");
            getline(cin, newDict);
        }while(file == newDict);

        //Keep datas in array
        Config config("modifiers.cfg");
        string mod[50];

        map<string, Config*> messages = config.getGroups(); // all groups
        const string messagePrefix = "mod"; // prefix for group name

        for (map<string, Config*>::iterator i = messages.begin(); i != messages.end(); ++i) {
            string groupName = i->first;
            Config* group = i->second;

            if (groupName.substr(0, messagePrefix.length()) == messagePrefix) {
                if (group->pString("name") == modifier)
                {
                    mod[0] = group->pString("data");
                    if (lvl == 0) lvl = group->pInt("level");
                }
            }
        }

        int contador = 1;
        string tmp;
        for (unsigned int i = 0; i < mod[0].size(); i++)
        {
            if (mod[0][i] == ',')
            {
                mod[contador] = tmp;
                tmp = "";
                contador++;
            }
            else
            {
                tmp += mod[0][i];
            }
        }
        mod[contador] = tmp;
        int sizeMods = 0;
        while(sizeMods < 50)
        {
            sizeMods++;
            if (mod[sizeMods] == "")
            {
                break;
            }
        }


        string tmpWord;
        while (f)
        {
            f >> line;
            //Generate and save modify
            for (int i = 1; i <= sizeMods; i++)
            {
                if (lvl == 1)
                {
                    tmpWord = mod[i] + line;
                    func::writeFile(newDict, tmpWord);
                }
                else if (lvl == 2)
                {
                    tmpWord = line + mod[i];
                    func::writeFile(newDict, tmpWord);
                }
                else if (lvl == 3)
                {

                    for (int j = 1; j <= sizeMods; j++)
                    {
                        tmpWord = "";
                        tmpWord = mod[i] + line + mod[j];
                        func::writeFile(newDict, tmpWord);
                    }
                }
                else if (lvl == 4)
                {
                    tmpWord = "";
                    for (unsigned int j = 0; j < line.size(); j++)
                    {
                        unsigned int varRandom = 2; //TO DO. random var
                        if (varRandom == j)
                        {
                            tmpWord += mod[i];
                        }
                        tmpWord += line[j];
                    }
                    func::writeFile(newDict, tmpWord);
                }
                else if (lvl == 5)
                {
                    tmpWord = mod[i];
                    for (unsigned int j = 0; j < line.size(); j++)
                    {
                        unsigned int varRandom = 2; //TO DO. random var
                        if (varRandom == j)
                        {
                            tmpWord += mod[i];
                        }
                        tmpWord += line[j];
                    }
                    for (int j = 1; j <= sizeMods+1; j++)
                    {
                        tmpWord += mod[j];
                        func::writeFile(newDict, tmpWord);
                    }
                }
            }
            //func::writeFile(newDict, line);
            //END Generator
        }
        f.close();
        func::clearDict(newDict);
    }else { cout << "Can't open file" << endl; }
}

void Run::modCapital(string file, int lvl)
{
    // Read file
    fstream f;
    f.open(file.c_str(), fstream::in | fstream::out | fstream::app);
    string line;
    if(f.is_open())
    {
        string newDict;
        do
        {
            cout << ("Name new dictionary: ");
            getline(cin, newDict);
        }while(file == newDict);

        if (lvl == 0)
        {
            //Keep datas in array
            Config config("modifiers.cfg");

            map<string, Config*> messages = config.getGroups(); // all groups
            const string messagePrefix = "mod"; // prefix for group name

            for (map<string, Config*>::iterator i = messages.begin(); i != messages.end(); ++i) {
                string groupName = i->first;
                Config* group = i->second;

                if (groupName.substr(0, messagePrefix.length()) == messagePrefix) {
                    if (group->pString("name") == "capital")
                    {
                        lvl = group->pInt("level");
                    }
                }
            }
        }


        while (f)
        {
            f >> line;

            //func::writeFile(newDict, line);

            if (lvl == 1 or lvl == 3)
            {
                if (file[0] <= 122 and line[0] >= 97)
                {
                    line[0] -= 32;
                }
            }
            if (lvl == 2 or lvl == 3)
            {
                if (line[line.size()-1] <= 122 and line[line.size()-1] >= 97)
                {
                    line[line.size()-1] -= 32;
                }
            }
            if (lvl == 4)
            {
                for (unsigned int j = 0; j < line.size(); j++)
                {
                    line[j] -= 32;
                }
            }
            if (lvl == 5)
            {
                string tmpLine = line;
                for (unsigned int i = 0; i < tmpLine.size(); i++)
                {
                    if (line[line.size()-1] <= 122 and line[line.size()-1] >= 97)
                    {
                        tmpLine = line;
                        tmpLine[i] -= 32;
                        func::writeFile(newDict, tmpLine);
                    }
                }
            }
            if (lvl == 6)
            {
                for (unsigned int i = 0; i < line.size(); i++)
                {
                    if (line[i] >= 65 and line[i] <= 90)
                    {
                        line[i] += 32;
                    }
                }
            }
            func::writeFile(newDict, line);
        }
        f.close();

        func::clearDict(newDict);
    }else { cout << "Can't open file" << endl; }
}

void Run::modRandom(string file, int lvl)
{

    // Read file
    fstream f;
    f.open(file.c_str(), fstream::in | fstream::out | fstream::app);
    string line;
    if(f.is_open())
    {
        string newDict;
        do
        {
            cout << ("Name new dictionary: ");
            getline(cin, newDict);
        }while(file == newDict);

        Config config("modifiers.cfg");
        string mod[3];

        map<string, Config*> messages = config.getGroups(); // all groups
        const string messagePrefix = "mod"; // prefix for group name

        for (map<string, Config*>::iterator i = messages.begin(); i != messages.end(); ++i) {
            string groupName = i->first;
            Config* group = i->second;

            if (groupName.substr(0, messagePrefix.length()) == messagePrefix) {
                if (group->pString("name") == "random")
                {
                    mod[0] = group->pString("data");
                    if (lvl == 0) lvl = group->pInt("level");
                }
            }
        }

        int contador = 1;
        for (unsigned int i = 0; i < mod[0].size(); i++)
        {
            if (mod[0][i] == '-')
            {
                contador++;
            }
            else
            {
                mod[contador] += mod[0][i];
            }
        }

        int tmpMin = atoi(mod[1].c_str());
        int tmpMax = atoi(mod[2].c_str());

        while (f)
        {
            f >> line;

            func::writeFile(newDict, line);
            ostringstream ss;
            string tmpWord;
            for (int i = tmpMin; i <= tmpMax; i++)
            {
                tmpWord = line;
                ss << i;

                if (lvl == 1)
                {
                    tmpWord = ss.str() + line;
                    func::writeFile(newDict, tmpWord);
                }
                else if (lvl == 2)
                {
                    tmpWord += ss.str();
                    func::writeFile(newDict, tmpWord);
                }
                else if (lvl == 3)
                {
                    tmpWord = ss.str() + line;
                    ostringstream zz;
                    string tmpWord2;
                    for (int j = tmpMin; j <= tmpMax; j++)
                    {
                        zz << j;
                        tmpWord2 = tmpWord + zz.str();
                        zz.str("");
                        func::writeFile(newDict, tmpWord2);
                    }
                }
                else if (lvl == 4)
                {
                    for (unsigned int j = 0; j < line.size(); j++)
                    {
                        unsigned int varRandom = 2; //TO DO. random var
                        if (varRandom == j)
                        {
                            tmpWord += ss.str();
                        }
                        tmpWord += line[j];
                    }
                    func::writeFile(newDict, tmpWord);
                }
                /*
                if (lvl == 5)
                {
                    tmpWord = line;
                    for (unsigned int i = 0; i < tmpWord.size(); i++)
                    {

                    }

                }
                */
                ss.str("");
            }

            //func::writeFile(newDict, tmpWord);
        }
        f.close();
        func::clearDict(newDict);
    }else { cout << "Can't open file" << endl; }
}

void Run::modComcat(string file)
{
    // Read file
    fstream f;
    fstream f2;
    string line;
    string line2;
    f.open(file.c_str(), fstream::in | fstream::out | fstream::app);
    f2.open(file.c_str(), fstream::in | fstream::out | fstream::app);

    if(f.is_open())
    {
        if(f2.is_open())
        {
            string newDict;
            do
            {
                cout << ("Name new dictionary: ");
                getline(cin, newDict);
            }while(file == newDict);

            Config config("modifiers.cfg");
            string mod[50];

            map<string, Config*> messages = config.getGroups(); // all groups
            const string messagePrefix = "mod"; // prefix for group name

            for (map<string, Config*>::iterator i = messages.begin(); i != messages.end(); ++i) {
                string groupName = i->first;
                Config* group = i->second;

                if (groupName.substr(0, messagePrefix.length()) == messagePrefix) {
                    if (group->pString("name") == "comcat")
                    {
                        mod[0] = group->pString("data");
                    }
                }
            }

            //Keep dates in array
            int contador = 1;
            string tmp;
            for (unsigned int i = 0; i < mod[0].size(); i++)
            {
                if (mod[0][i] == ',')
                {
                    mod[contador] = tmp;
                    tmp = "";
                    contador++;
                }
                else
                {
                    tmp += mod[0][i];
                }
            }
            mod[contador] = tmp;

            int sizeMods = -1;
            while(sizeMods < 50)
            {
                if (mod[sizeMods] == "")
                {
                    break;
                }
                sizeMods++;
            }
            sizeMods--;

            while (f)
            {
                f >> line;
                func::writeFile(newDict, line);
                while(f2)
                {
                    f2 >> line2;
                    func::writeFile(newDict, line);
                    if(sizeMods > 0)
                    {
                        for (int i = 1; i <= sizeMods; i++)
                        {
                            func::writeFile(newDict, line+mod[i]+line2);
                        }
                    }
                    else
                    {
                        func::writeFile(newDict, line+line2);
                    }

                }
                f2.clear();
                f2.seekg(0, ios::beg);
            }
            f.close();
            f2.close();
            func::clearDict(newDict);
        }else { cout << "Can't open file" << endl; }
    }else { cout << "Can't open file" << endl; }

}


void Run::deleteLimitCharacters(string file, unsigned int minCharac, unsigned int maxCharac)
{

    // Read file
    fstream f;
    f.open(file.c_str(), fstream::in | fstream::out | fstream::app);
    string line;
    if(f.is_open())
    {
        string newDict;
        do
        {
            cout << ("Name new dictionary: ");
            getline(cin, newDict);
        }while(file == newDict);

        while (f)
        {
            f >> line;

            if (line.size() <= maxCharac and line.size() >= minCharac)
            {
                func::writeFile(newDict, line);
            }
        }
        f.close();

        func::clearDict(newDict);
    }else { cout << "Can't open file" << endl; }

}
