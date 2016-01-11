#include <iostream>
#include <fstream>
#include "vector.h"
#include <string>
using namespace std;


struct eMailMsg {
    string to;
    string from;
    string message;
    string subject;
    int date;
    int time;
};

void readFile(Vector<eMailMsg> &messages, string filename);
void RemoveSpam(Vector<eMailMsg> &messages);

int main() {
    
    string filename = "spam.txt";
    Vector<eMailMsg> messages;
    readFile(messages, filename);
    RemoveSpam(messages);
    return 0;
}

void tokenize(string str, Vector<string> &token_v, char delimeter){
    size_t start = str.find_first_not_of(delimeter), end=start;
    
    while (start != string::npos){
        // Find next occurence of delimiter
        end = str.find(delimeter, start);
        // Push back the token found into vector
        token_v.push_back(str.substr(start, end-start));
        // Skip all occurences of the delimiter to find new start
        start = str.find_first_not_of(delimeter, end);
    }
}

eMailMsg split(string line) {
    eMailMsg msg;
    Vector<string> tokens;
    tokenize(line, tokens, ',');
    msg.to = tokens[0];
    msg.from = tokens[1];
    msg.message = tokens[2];
    msg.subject = tokens[3];
    msg.date = stoi(tokens[4]);
    msg.date = stoi(tokens[5]);
    return msg;
}

void readFile(Vector<eMailMsg> &messages, string filename) {
    
    ifstream infile;
    infile.open(filename.c_str());
    
    while (true) {
        string line;
        getline(infile, line);
        if (infile.fail()) break;
        messages.add(split(line));
    }
    
    
}


void RemoveSpam(Vector<eMailMsg> &messages) {
    
    for (int i = messages.size() - 1; i >= 0; i--) {
        if (messages[i].subject.find("SPAM") == 0) {
            messages.remove(i);
        }
    }
    
    cout << messages.size() << endl;
    cout << messages[0].to << endl;
    cout << messages[1].to << endl;
}
























