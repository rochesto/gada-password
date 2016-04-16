#include "functions.h"
#include <dirent.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <vector>
#include <algorithm>

namespace func{

    using namespace std;

    void createMofifierFile()
    {
        bool exist = false;
        string file = "modifiers.cfg";

        DIR *dr;
        struct dirent *drnt;

        dr = opendir("./");

        if (dr)
        {
            while ((drnt = readdir(dr)))
            {
                if(drnt->d_name == file){
                    exist = true;
                }
            }
            closedir(dr);
        }
        if (!exist)
        {
            fstream f;
            f.open("modifiers.cfg", fstream::in | fstream::out | fstream::app);
            if(f)
            {
                f << "# Modifiers Config File" << endl << endl;
                f << "# SIZE WORD" << endl << endl;
                f << "min = 3" << endl;
                f << "max = 20" << endl << endl;
                f << "# BRUTE FORCE" << endl << endl;
                f << "brute = abcdefghijklmnopqrstuvwxyz" << endl << endl;
                f << "# MODIFIERS" << endl;
                f << "mod1 = (" << endl;
                f << "   name = 'date'" << endl;
                f << "   level = 2" << endl;
                f << "   data = 2000,2001" << endl;
                f << ")" << endl << endl;
                f << "mod2 = (" << endl;
                f << "   name = 'capital'" << endl;
                f << "   level = 1" << endl;
                f << ")" << endl << endl;
                f << "mod3 = (" << endl;
                f << "   name = 'random'" << endl;
                f << "   level = 1" << endl;
                f << "   data = 0-100" << endl;
                f << ")" << endl << endl;
                f << "mod4 = (" << endl;
                f << "   name = 'special'" << endl;
                f << "   level = 1" << endl;
                f << "   data = #,&,?" << endl;
                f << ")" << endl << endl;
                f << "mod5 = (" << endl;
                f << "   name = 'comcat'" << endl;
                f << "   level =" << endl;
                f << "   data = and,y,&" << endl;
                f << ")" << endl << endl;
                f.close();
            }else{
                cout << "Can't open file to write" << endl;
            }
        }
    }

    void lsDir()
    {
        DIR *dr;
        struct dirent *drnt;

        string exclude[] = {".", ".."};
        int contador = 0;

        dr = opendir("./");

        if (dr)
        {
            while ((drnt = readdir(dr)))
            {
                if(drnt->d_name != exclude[0] and drnt->d_name != exclude[1]){
//                    cout << contador+1 << " - ";
                    cout << " # " << drnt->d_name << endl;
                    contador++;
                }
            }
            closedir(dr);
        }else{
            cout << "Can't open dictionary directory" << endl;
        }

    }

    //Delete ditionary
    void rmDic(string name)
    {
        string op;
        if (name != "")
        {
            op = name.c_str();
        }
        else
        {
            lsDir();
            cout << "Name of dictionary > ";
            cin >> op;
        }
        const char * op2 = op.c_str();
        char command[100] = "rm ";
        strcat(command, op2);
        system(command);

    }

    void cls(){

        system("clear");
    }

    void createDir(string name)
    {
        string command = "mkdir ";
        command += name;
        char com[50];
        for (unsigned int i = 0; i < command.size(); i++)
        {
            com[i] = command[i];
        }

        system(com);
    }

    void writeFile(string name, string text)
    {
        fstream f;
        f.open(name.c_str(), fstream::in | fstream::out | fstream::app);
        if(f)
        {
            f << text << endl;
            f.close();
        }else{
            cout << "Can't open file to write" << endl;
        }
    }

    void clearDict(string dict)
    {
        //Copy dict in tmp file to work
        string tmpDict = "/tmp/dict-tmp";

        fstream f(dict.c_str(), fstream::in | fstream::out | fstream::app);

        if (f)
        {
            fstream f_tmp;
            f_tmp.open(tmpDict.c_str(), fstream::in | fstream::out | fstream::app);
            if (f_tmp)
            {
                cout << "Cleaning dictionary... ";
                string word;
                string wordCopy;
                //Deleting white lines
                while(!f.eof())
                {
                    f >> word;

                    if (word.size() > 2)
                    {
                        for (unsigned int i = 0; i < word.size(); i++)
                        {
                            if(word[i] != ' ')
                            {
                                wordCopy += word[i];
                            }
                        }
                        f_tmp << wordCopy << endl;
                        wordCopy = "";
                    }
                }
                f_tmp.close();
            }
            else{ cout << "Can't create a tmp file!!" << endl; }

            f.close();
        }
        else{ cout << "Can't read dictionary!!" ;}

        //Copy tmpDict in user dictionary
        string command = "cp ";
        command += tmpDict;
        command += " ";
        command += dict;
        system(command.c_str());
        //Delete tmpFile
        command = "rm ";
        command += tmpDict;
        system(command.c_str());

        cout << "Ok" << endl;
        sortDict(dict);

    }

    // Sort and delete duplicates words in a file
    void sortDict(string file)
    {

        //Copy dict in tmp file to work
        string tmpDict = "/tmp/dictSort-tmp";

        fstream f(file.c_str(), fstream::in | fstream::out | fstream::app);

        if (f)
        {
            fstream f_tmp;
            f_tmp.open(tmpDict.c_str(), fstream::in | fstream::out | fstream::app);
            if (f_tmp)
            {
                cout << "Sorting dictionary... ";
                string word;
                vector<string> words;
                //Deleting white lines
                while(!f.eof())
                {
                    getline(f, word);
                    words.push_back(word);
                }
                sort(words.begin(), words.end());
                words.erase(unique(words.begin(), words.end()), words.end());

                for (vector<string>::iterator it = words.begin(); it != words.end(); it++)
                {
                    f_tmp << *it << endl;
                }

                f_tmp.close();
            }
            else{ cout << "Can't create a tmp file!!" << endl; }

            f.close();
        }
        else{ cout << "Can't read dictionary!!" ;}

        //Copy tmpDict in user dictionary
        string command = "cp ";
        command += tmpDict;
        command += " ";
        command += file;
        system(command.c_str());
        //Delete tmpFile
        command = "rm ";
        command += tmpDict;
        system(command.c_str());

        cout << "Ok" << endl;
    }

    void comcatDics(string dic1, string dic2)
    {
        string newDict;
        do
        {
            cout << ("Name new dictionary: ");
            getline(cin, newDict);
        }while(dic1 == newDict or dic2 == newDict);

        cout << "Concatenating dictionaries... ";
        string command = "cat ";
        command += dic1;
        command += " >> ";
        command += newDict;
        system(command.c_str());

        command = "cat ";
        command += dic2;
        command += " >> ";
        command += newDict;
        system(command.c_str());
        cout << "Ok" << endl;
        clearDict(newDict);
    }
}




