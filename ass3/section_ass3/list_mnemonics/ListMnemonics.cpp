//
// Created by Ilya Rudyak on 2/23/16.
//

#include <iostream>
#include "ListMnemonics.h"

ListMnemonics::ListMnemonics(string strOfDigits) {
    this->strOfDigits = strOfDigits;
}

void ListMnemonics::listMnem() {
    listMnem("", strOfDigits);
}

// ---------------- helper functions --------------

void ListMnemonics::listMnem(string acc, string rest) {

    if (rest.size() == 0) {
        cout << acc << endl;
        mnem.insert(acc);
    } else {
        char ch = rest[0];
        string mnem = kMnemMap.at(ch);
        for (int i = 0; i < mnem.size(); ++i) {
            listMnem(acc + mnem[i], rest.substr(1));
        }
    }
}


















