#include "CoreApp.h"

#include <iostream>
#include <string>
#include <functions.h>

using namespace std;
int main(int argc, char *argv[], char* envp[])
{
    func::createMofifierFile();

    if (argc == 1)
    {
        CoreApp core;
    }
    else
    {

    }

    return 0;
}
