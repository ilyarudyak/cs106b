
#include <iostream>
#include <string>
#include <set>
#include "simpio.h"
#include "lexicon.h"
using namespace std;

set<string> listMnemonics(string str);
void printSet(set<string> s) {
    for(auto str: s) {
        cout << str << " ";
    }
    cout << endl;
}

Lexicon lex("words");

int main() {
    
    set<string> prefixes = listMnemonics("72547");
    printSet(prefixes);
    for (string prefix: prefixes) {
        
        foreach (string s in lex) {
            if (s.find(prefix) == 0) {
                cout << s << endl;
            }
        }
    }
    
    return 0;
}

string digitLetters(char ch) {
    switch (ch) {
        case '0': return ("0");
        case '1': return ("1");
        case '2': return ("abc");
        case '3': return ("def");
        case '4': return ("ghi");
        case '5': return ("jkl");
        case '6': return ("mno");
        case '7': return ("prs");
        case '8': return ("tuv");
        case '9': return ("wxy");
        default: cerr << "Illegal digit" << endl;
    }
    return "";
}


void recursiveMnemonics(string prefix, string rest, set<string> &mnem) {
    
    if (!lex.containsPrefix(prefix)) {
        return;
    }
    
    if (rest.length() == 0) {
        mnem.insert(prefix);
    }
    
    else {
        string options = digitLetters(rest[0]);
        for (int i = 0; i < options.length(); i++) {
            recursiveMnemonics(prefix + options[i], rest.substr(1), mnem);
        }
    }

}

set<string> listMnemonics(string str) {
    set<string> res;
    recursiveMnemonics("", str, res);
    return res;
}





















