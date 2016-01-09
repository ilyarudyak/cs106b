#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
using namespace std;

string CensorString1(string text, string remove);
void CensorString2(string & text, string remove);


int main() {
    cout << CensorString1("Stanford University", "nt") << endl;
    
    string s = "Stanford University";
    CensorString2(s, "nt");
    cout << s << endl;
    
    return 0;
}

string CensorString1(string text, string remove) {
    
    string result;
    for (int i = 0; i < text.length(); i++) {
        if (remove.find(text[i]) == string::npos) {
            result += text[i];
        }
    }
    return result;
}

void CensorString2(string & text, string remove) {
    int pos = string::npos;
    while (true) {
        for (int i = 0; i < remove.length(); i++) {
            pos = text.find(remove[i]);
            if (pos != string::npos) {
                text.erase(pos, 1);
            }
        }
        if (pos == string::npos) {
            break;
        }
    }
}
















