/*
 * File: FleschKincaid.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Flesch-Kincaid problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
//#include "console.h"
#include "tokenscanner.h"
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;


int syl_count(string token) {
    
    string vowels = "aeiouy";
    int vc = 0;
    bool vbefore = false;
    
    for (int i = 0; i < token.length(); i++) {
        if (vowels.find(tolower(token[i])) != string::npos) {
            if (!vbefore) {
                if (i == token.length() - 1 && tolower(token[i]) == 'e') {
                    break;
                } else {
                    vc++;
                }
            }
            vbefore = true;
        } else {
            vbefore = false;
        }
    }
    return max(vc, 1);
}

int main() {
    
    ifstream infile;
    infile.open("1984.txt");
    
    TokenScanner scanner(infile);
    scanner.ignoreWhitespace();
    scanner.addWordCharacters("'");
    
    int wc = 0, sec =0, syc = 0;
    
    while (scanner.hasMoreTokens()) {
        string token = scanner.nextToken();
        if (isalpha(token[0])) {
            wc++;
            syc += syl_count(token);
        } else if (token == "." || token == "!" || token == "?") {
            sec++;
        }
    }
    cout << "Flesch-Kincaid=" << -15.59 + (.39 * wc / sec)
        + (11.8 * syc / wc) << endl;
    infile.close();

    return 0;
}














