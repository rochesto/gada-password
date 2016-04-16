#include "Words.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

#include "functions.h"

using namespace std;

Words::Words()
{
    //ctor
}

Words::~Words()
{
    //dtor
}

// Read words from terminal and save in a dictionary input
void Words::readWords()
{

    string dictName;
    cout << "Name of new dictionary: ";
    cin >> dictName;

    string word;
    cout << "Input words, 'quit' to exit" << endl;
    while((word != "quit") && (word != "q"))
    {
        cout << "Word >> ";
        cin >> word;

        func::writeFile(dictName, word);

    }

    func::clearDict(dictName);
}


void Words::readFile(string file)
{
    fstream f;
    f.open(file.c_str(), fstream::in | fstream::app);
    if(f)
    {
        string namefile;
        cout << "Name for dictionary: ";
        cin >> namefile;

        char ch;
        string word;

        while(f >> noskipws >> ch)
        {
            //if(ch == ' ' or ch == '\n' or ch == '<' or ch == '>' or ch == '/' or ch == '=' or ch == '!' or ch == '{' or ch == '}' or ch == ',' or ch == '.' or ch == '"' or ch == '\'' or ch == '(' or ch == ':' or ch == ';' or ch == '#' or ch == '+' or ch == '*' or ch == '%' or ch == '&' or ch == ')' or ch == '-' )
            if ((ch < 48) or (ch >= 58 and ch <= 64) or (ch >= 91 and ch <= 96) or (ch > 122))
            {
                func::writeFile(namefile, word);
                word = "";
            }
            else
            {
                word += ch;

            }
        }

        func::clearDict(namefile);
    }
    else
    {
        cout << "Can't read file: " << file << endl;
    }
}

void Words::readUrl(string url, string recursive)
{
    string commamd;
    if (recursive == "all") commamd = "wget -O /tmp/gada-web.html --recursive ";
    else commamd = "wget -O /tmp/gada-web.html ";
    commamd += url;

    system(commamd.c_str());

    readFile("/tmp/gada-web.html");
}

void Words::readUrl()
{
    string tmp = " /tmp/gada-web.html ";
    string url;
    cout << "Enter URL: ";
    cin >> url;
    string commamd;
    commamd = "wget -O ";
    commamd += tmp;
    commamd += url;

    system(commamd.c_str());

    readFile(tmp);
}

void Words::brute(string namefile, string data, int sizeChar)
{
    string word;
    int sizeData = data.size();
    int counter = 0;
    int pos = sizeChar-1;
    int flags[sizeChar];

    //Initialize variables
    for (int i = 0; i < sizeChar; i++){
        word += data[0];
        flags[i] = 0;
    }

    //Loop
    cout << "Words lenght: " << sizeChar << endl;
    cout << "Working... ";
    while(pos >= 0)
    {

        for (int i = 0; i < sizeChar; i++)
        {
            word[i] = data[flags[i]];
        }

        flags[sizeChar-1]++;
        for (int i = sizeChar-1; i >= 0; i--)
        {
            if (flags[i] > sizeData-1 and i != 0)
            {
                flags[i-1] += 1;
                flags[i] = 0;
            }
            else if(flags[i] > sizeData-1 and i == 0 ) pos = -1;
        }

        func::writeFile(namefile, word);
        counter++;
    }
    cout << "Finish" << endl;
    cout << "Words: " << counter << endl;
}
