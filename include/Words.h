#ifndef WORDS_H
#define WORDS_H

#include <string>

using namespace std;

class Words
{
    public:
        Words();
        virtual ~Words();
        void readWords();
        void readFile(string file = "");
        void readUrl();
        void readUrl(string, string recusive = "");
        void brute(string file, string data, int lengWord);
    protected:
    private:
};

#endif // WORDS_H
