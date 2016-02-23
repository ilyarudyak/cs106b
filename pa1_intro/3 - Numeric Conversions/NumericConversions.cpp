/*
 * File: NumericConversions.cpp
 * ---------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Numeric Conversions problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include <string>
//#include "console.h"
#include "strlib.h"
#include <cmath>
using namespace std;

/* Function prototypes */

string intToString(int n);
int stringToInt(string str);

/* Main program */

int main() {
    cout << stringToInt("42") << endl;
    return 0;
}

int stringToInt2(string s, int n, int k) {
    
    if (s.length() == 1) {
        return (s[0] - (int ) '0') * pow(10, k) + n;
    }
    return stringToInt2(s.substr(0, s.length() - 1),
                        (n + s[s.length() - 1] - (int) '0') * pow(10, k),
                        k + 1);
}

int stringToInt(string str) {
    return stringToInt2(str, 0, 0);
}

string intToString2(string s, int n) {
    
    
    if (n < 10) {
        string s1 = (string(1, char(n + '0'))) + s;
        return s1;
    }
    
    string s2 = (string(1, char(n % 10 + '0'))) + s;
    return intToString2(s2, n / 10);
}

string intToString(int n) {
    return intToString2("", n);
}





























