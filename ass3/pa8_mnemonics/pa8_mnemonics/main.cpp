#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

set<string> mnemonics(string s);
set<string> permute(string s);


map<int, string> dial = {
    {2, "ABC"}, {3, "DEF"}, {4, "GHI"},
    {5, "JKL"}, {6, "MNO"}, {7, "PRS"},
    {8, "TUV"}, {9, "WXY"}
};

int main() {
    
//    string s = "732";
//    int n = stoi(s.substr(2, 1));
//    cout << n << endl;

    string s = "732";
    set<string> set = mnemonics(s);
    for (auto s: set) {
        cout << s << " ";
    }
    cout << set.size() << endl;
    return 0;
}

void printSet(set<string> set) {
    for (auto s: set) {
        cout << s << " ";
    }
    cout << endl;
}


set<string> mnemonics(string s, int k) {
    
    set<string> mnem;
    
    if (k == 3) {
        mnem.insert("");
        return mnem;
    }
    
    cout << s.substr(k, 1) << endl;
    int n = stoi(s.substr(k, 1));
    string s2 = dial[n];
    for (int i = 0; i < 3; i++) {
        for (auto s3: mnemonics(s, k + 1)) {
            mnem.insert(s2.substr(i, 1) + s3);
        }
    }
    return mnem;
}

set<string> mnemonics(string s) {
    return mnemonics(s, 0);
}

set<string> permute(string s) {
    
    if (s.size() == 0) {
        // set contains empty string, NOT an empty set
        return set<string>({""});
    }
    
    set<string> perm;
    for (int i = 0; i < s.size(); i++) {
        set<string> set = permute(s.substr(0, i) + s.substr(i+1));
//        printSet(set);
        for (auto s2 : set) {
            perm.insert(s[i] + s2);
        }
    }
    return perm;
}














