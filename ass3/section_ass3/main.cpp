#include <iostream>
#include <vector>
#include "list_mnemonics/ListMnemonics.h"
#include "measure/Measure.h"

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

int gcd(int x, int y) {

    if (x % y == 0) {
        return y;
    } else {
        return gcd(y, x % y);
    }
}

void reverseString(string acc, string rest) {

    if (rest.size() == 0) {
        cout << acc << endl;
    } else {
        reverseString(acc + rest.back(), rest.substr(0, rest.size() - 1));
    }
}
void reverseString(string s) {
    reverseString("", s);
}

int main() {

    reverseString("hello my friend!");

//    cout << gcd(32, 56) << endl;

//    vector<int> weights = {1, 3};
//    Measure m(weights);
//    cout << m.isMeasurable(2) << endl;


//    permute("ABC");
//    subset("ABC");

//    ListMnemonics lm("723");
//    lm.listMnem();
//    cout << lm.getMnem().size() << endl;

    return 0;
}

















