#include "input.h"
#include <iostream>
#include <locale>

using namespace std;

input::input()
{
    command = "";
}

input::~input()
{
    //dtor
}

string * input::readCommand()
{
    clearArray(5);
    cout << "gada>> ";
    getline(cin, command);
    history[contador] = command;//Historual
    contador++;
    if(contador >= 50)
    {
        contador = 0;    //Historual
    }
    splitCommand(command);
    lowerCommand();

    return commands;
}
void input::splitCommand(string & command)
{
    int cont = 0;
    for (unsigned int i = 0; i < command.size() && cont < 5; i++)
    {
        if (command[i] == ' ')
        {
            cont++;
        }
        else
        {
            commands[cont] += command[i];
        }
    }
}
void input::lowerCommand()
{
    //Tranform string to lowercase
    locale loc;
    for (unsigned int i = 0; i < command.size(); i++)
    {
        commands[0][i] = tolower(commands[0][i], loc);
    }
}

void input::clearArray(int siz)
{
    for (int i = 0; i < siz; i++)
    {
        commands[i] = "";
    }
}
