//
// Created by Ilya Rudyak on 5/30/16.
//

#ifndef PA4_BOGGLE_DICTIONARY_H
#define PA4_BOGGLE_DICTIONARY_H

#include <set>
#include <fstream>
using namespace std;

class Dictionary {

public:
    Dictionary() {
        dictionary = {"GEEKS", "FOR", "QUIZ", "GO"};
    }
    Dictionary(fstream &in) {
        string word;
        while (in >> word) {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            dictionary.insert(word);
        }
    }
    bool isWord(string &str) {
        return dictionary.count(str) > 0;
    }

private:
    set<string> dictionary;

};


#endif //PA4_BOGGLE_DICTIONARY_H
