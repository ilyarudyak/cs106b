#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;

char MostFrequentCharacter(ifstream &infile, int &n);


int main() {
    ifstream infile;
    infile.open("Jabberwocky.txt");
    int n = 0;
    cout << MostFrequentCharacter(infile, n) << endl;
    infile.close();
    return 0;
}

char MostFrequentCharacter(ifstream &infile, int &n) {
    map<char, int> freq;
    while (true) {
        int ch = infile.get();
        if (ch == EOF) break;
        
        char ch2 = tolower((char)ch);
        freq[ch2]++;
    }
    
    char ch_max;
    for (map<char, int>::iterator it = freq.begin(); it != freq.end(); it++) {
        if (it->first != ' ' && it->second > n) {
            n = it->second;
            ch_max = it->first;
        }
//        cout << "key=" << it->first << " value=" << freq[it->first] << endl;
    }
    
    return ch_max;
}





























