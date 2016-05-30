#include <iostream>
#include "Boggle.h"

using namespace std;

int main() {

//    vector<vector<char>> bv = {
//            {'G','I','Z'},
//            {'U','E','K'},
//            {'Q','S','E'}
//    };
//
//    Boggle boggle(bv);
//    boggle.findWords();

    vector<vector<char>> bv = {
            {'e','e','c','a'},
            {'a','l','e','p'},
            {'h','n','b','o'},
            {'q','t','t','y'}
    };

    Boggle boggle(bv, true);
    boggle.findWords();
    for (auto word : boggle.getWords()) {
        cout << word << " ";
    }
    cout << endl;
    cout << "size=" << boggle.getWords().size() << endl;

    return 0;
}