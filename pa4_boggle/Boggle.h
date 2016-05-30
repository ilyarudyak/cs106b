//
// Created by Ilya Rudyak on 5/30/16.
//

#ifndef PA4_BOGGLE_BOGGLE_H
#define PA4_BOGGLE_BOGGLE_H

#include <vector>
#include <set>
#include "Dictionary.h"
using namespace std;

class Boggle {

public:
    Boggle(const vector<vector<char>> &boggle,
           bool isRealDict = false) : boggle(boggle) {
        if (isRealDict) {
            fstream in("words");
            dictionary = Dictionary(in);
        }
    }

    void findWords() {

        string s = "";
        size_t N = boggle.size();
        vector<vector<bool>> visited(N, vector<bool>(N, false));

        for (int i = 0; i < boggle.size(); i++) {
            for (int j = 0; j < boggle.size(); j++) {
                findWords(i, j, s, visited);
            }
        }
    }


    const set<string> &getWords() const {
        return words;
    }

private:
    vector<vector<char>> boggle;
    Dictionary dictionary;
    set<string> words;

    void findWords(int i, int j, string &str, vector<vector<bool>> visited) {

        if (i < 0 || i >= boggle.size() ||
            j < 0 || j >= boggle.size() ||
            visited[i][j]) {
            return;
        }

        visited[i][j] = true;
        str += boggle[i][j];

        if (dictionary.isWord(str)) {
            if (str.size() > 3) {
//                cout << str << endl;
                words.insert(str);
            }

        }

        for (int row = i-1; row <= i+1; row++) {
            for (int col = j-1; col <= j+1; col++) {
                findWords(row, col, str, visited);
            }
        }

        str.erase(str.length()-1);
        visited[i][j] = false;

    }
};

#endif //PA4_BOGGLE_BOGGLE_H














