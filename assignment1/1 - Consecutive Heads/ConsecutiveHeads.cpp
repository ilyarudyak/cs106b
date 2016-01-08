/*
 * File: ConsecutiveHeads.cpp
 * --------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Consecutive Heads problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include "console.h"
#include "random.h"
using namespace std;

int main() {
    
    setRandomSeed(0);
    int hcount = 0;
    int fcount = 0;
    
    while (true) {
        if (randomChance(.5)) {
            cout << "heads" << endl;
            hcount++;
            fcount++;
            if (hcount == 3) {
                cout << "it took " << fcount <<
                " flips to get 3 consequtive heads." << endl;
                break;
            }
        } else {
            cout << "tails" << endl;
            hcount = 0;
            fcount++;
        }
    }
    return 0;
}





