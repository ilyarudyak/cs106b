#include <iostream>
#include <fstream>
#include "vector.h"
#include <algorithm>
#include <numeric>
using namespace std;

void CountLetters(string filename);

int main() {
    
    string filename = "Jabberwocky.txt";
    CountLetters(filename);
    
    return 0;
}


void CountLetters(string filename) {
    
    Vector<int> freq(26);
 
    ifstream infile;
    infile.open(filename.c_str());
    
    int ch;
    while ((ch = infile.get()) != EOF) {
        
        char ch1 = (char) ch;
        if (isalpha(ch1)) {
            int i = (int) (tolower(ch1) - 'a');
            freq[i]++;
        }
    
    }

    
    infile.close();
    
    for (int i = 0; i < freq.size(); i++) {
        cout << (char) (i + 'a') << ":" << freq[i] << " ";
    }
        cout << endl;
}

























