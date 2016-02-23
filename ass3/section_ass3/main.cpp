#include <iostream>
#include "list_mnemonics/ListMnemonics.h"

using namespace std;

void permute(string acc, string str) {

    if (str.size() == 1) {
        cout << acc + str << endl;
    }

    for (int i = 0; i < str.size(); ++i) {
        string rest = str;
        permute(acc + str[i], rest.erase((unsigned long) i, 1));
    }

}

void permute(string str) {
    permute("", str);
}

void subset(string acc, string str) {

    if (str.size() == 0) {
        cout << acc << endl;
    } else {
        subset(acc + str[0], str.substr(1));
        subset(acc, str.substr(1));
    }
}

void subset(string str) {
    subset("", str);
}

int main() {

//    permute("ABC");
//    subset("ABC");

    ListMnemonics lm("723");
    lm.listMnem();



    return 0;
}

















