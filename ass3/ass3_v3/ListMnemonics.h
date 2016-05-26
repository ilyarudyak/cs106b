//
// Created by Ilya Rudyak on 5/26/16.
//

#ifndef ASS3_V3_LISTMNEMONICS_H
#define ASS3_V3_LISTMNEMONICS_H

#include <vector>
using namespace std;

class ListMnemonics {
public:

    vector<string> mnemonics =  {
            {}, {}, {"ABC"}, {"DEF"}, {"GHI"}, {"JKL"}, {"MNO"},
            {"PRS"}, {"TUV"}, {"WXY"}
    };

    void list(string s) {
        list("", s);
    }

private:
    void list(string acc, string rest) {

        if (rest.empty()) {
            cout << acc << endl;
            return;
        }

        string smnem = mnemonics[rest[0] - '0'];
        for (int i = 0; i < smnem.size(); ++i) {
            list(acc + smnem[i], rest.substr(1));
        }
    }

};

#endif //ASS3_V3_LISTMNEMONICS_H
