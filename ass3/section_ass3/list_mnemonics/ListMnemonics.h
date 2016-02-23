//
// Created by Ilya Rudyak on 2/23/16.
//

#ifndef SECTION_ASS3_LISTMNEMONICS_H
#define SECTION_ASS3_LISTMNEMONICS_H

#include <string>
#include <map>
#include <set>

using namespace std;

class ListMnemonics {

public:

    using MnemMap = map<char, string>;

    const MnemMap kMnemMap = {
            {'2', "ABC"},
            {'3', "DEF"},
            {'4', "GHI"},
            {'5', "JKL"},
            {'6', "MND"},
            {'7', "PRS"},
            {'8', "TUV"},
            {'9', "WXY"}
    };

    ListMnemonics() = default;
    ListMnemonics(string strOfDigits);

    void listMnem();


    const set<string> &getMnem() const {
        return mnem;
    }

private:

    string strOfDigits;
    set<string> mnem;


    void listMnem(string acc, string rest);

};


#endif //SECTION_ASS3_LISTMNEMONICS_H


























