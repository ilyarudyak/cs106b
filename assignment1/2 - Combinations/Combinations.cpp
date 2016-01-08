/*
 * File: Combinations.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Combinations problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include <cstdio>
#include "console.h"
using namespace std;

int comb(int n, int k) {
    
    if (n == 0 || n == 1 || k == 0 || n == k) {
        return 1;
    }
    
    return comb(n - 1, k - 1) + comb(n - 1, k);
}

int main() {
    for (int n = 0; n < 10; n++) {
        for (int i = 0; i < 9 - n; i++) {
            printf("   ");
        }
        for (int k = 0; k <=n; k++) {
            printf("%3d   ", comb(n, k));
        }
        printf("\n");
    }
    return 0;
}
