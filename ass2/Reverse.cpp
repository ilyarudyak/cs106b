#include <iostream>
#include <fstream>
#include "stack.h"
#include "queue.h"
#include <string>
using namespace std;

void reverse(Queue<int> &queue);
void readFile(Queue<int> &queue, string filename);


int main() {
    
    string filename = "reverse.txt";
    Queue<int> queue;
    readFile(queue, filename);
    reverse(queue);
    return 0;
}

void readFile(Queue<int> &queue, string filename) {
    
    ifstream infile;
    infile.open(filename.c_str());
    
    while (true) {
        string line;
        getline(infile, line);
        if (infile.fail()) break;
        queue.enqueue(stoi(line));
    }
    
    infile.close();
//    cout << queue.size() << endl;
}

void reverse(Queue<int> &queue) {
 
    Stack<int> stack;
    
    int n = queue.size();
    for (int i = 0; i < n; i++) {
        stack.push(queue.dequeue());
    }

    
    for (int i = 0; i < n; i++) {
        cout << stack.pop() << endl;
    }
}



























