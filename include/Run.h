#ifndef RUN_H
#define RUN_H

#include <string>

using namespace std;

class Run
{
    public:
        Run();
        virtual ~Run();
        void runMods(string modifier, string dict, int lvl = 0);
        void multiRun(); //Execute all modifiers cofigured in a file
        void deleteLimitCharacters(string file, unsigned int minCharac = 0, unsigned int maxCharac = 0);
    protected:
    private:
        void modListsWords(string file, string modifier, int lvl = 0);
        void modCapital(string file, int lvl);
        void modRandom(string file, int lvl);
        void modComcat(string file);
};

#endif // RUN_H
