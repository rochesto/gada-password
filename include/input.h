/*********************************

Class input.h

Read input command line and Return the first three words in an pointer.

return array[3]

    Author: Rochesto
*********************************/

#ifndef INPUT_H
#define INPUT_H
#include <string>


class input
{
    public:
        input();
        virtual ~input();
        std::string * readCommand();
    protected:
    private:
        std::string command;
        std::string commands[5];
        std::string history[50];
        int contador = 0;

        void splitCommand(std::string &); //Split command in 3 words, delimiter space. example: (run dates 3)
        void lowerCommand(); //Lowercase all command
        void clearArray(int); //Reset commands array
};

#endif // INPUT_H
