
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
using namespace std;

string readFile(ifstream &in);
string process(map<string, vector<string>> &seeds, string &text);
void printMap(map<string, vector<string>> &seeds);
string randStr(map<string, vector<string>> &seeds, string &maxSeed);


const int ORDER = 2;
const int OUTPUT = 2000;

int main() {
    
    ifstream in("tomsawyer.txt");
    string text = readFile(in);
    map<string, vector<string>> seeds;
    string maxSeed = process(seeds, text);
//    printMap(seeds);
//    cout << "maxSeed=" << maxSeed << endl;
    cout << randStr(seeds, maxSeed) << endl;
    return 0;
}


string process(map<string, vector<string>> &seeds, string &text) {
    
    string maxSeed = "";
    int max = 0;
    for (int i = 0; i < text.length() - 1; i += ORDER) {
        string seed = text.substr(i, ORDER);
        string next = text.substr(i + ORDER, 1);
        seeds[seed].push_back(next);
        if (seeds[seed].size() > max && seed != "  ") {
            maxSeed = seed;
            max = (int) seeds[seed].size();
        }
    }
    return maxSeed;
}

string randStr(map<string, vector<string>> &seeds, string &maxSeed) {
    string rs = "";
    string seed = maxSeed;
    for (int i = 0; i < OUTPUT; i++) {
        vector<string> next = seeds[seed];
        if (next.size() == 0) {
            break;
        }
        int k = rand() % next.size();
        rs += next[k];
        seed = seed[1] + next[k];
    }
    
    return rs;
}


string readFile(ifstream &in) {
    
    string text = "";
    string line = "";
    while (getline(in, line)) {
        text += line;
    }
    return text;
}

string printVector(vector<string> &next) {
    string res = "";
    for(auto s: next) {
        res += s + " ";
    }
    return res;
}

void printMap(map<string, vector<string>> &seeds) {
    
    for (auto seed : seeds) {
        cout << seed.first << ": " << printVector(seed.second) << ", " << endl;
    }
}














