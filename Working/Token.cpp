#include <iostream>
#include "stack.h"
#include <string>
#include "tokenscanner.h"
using namespace std;

bool IsCorrectlyNested(string html);


int main() {
    
    string html = "<html><b><i>CS106 rules!</i></b></html>";
    cout << IsCorrectlyNested(html) << endl;
    return 0;
}

bool IsCorrectlyNested(string html) {
 
    TokenScanner scanner(html);
    Stack<string> tokens;
    while (scanner.hasMoreTokens()) {
        string token = scanner.nextToken();
        if (token == "<") {
            token = scanner.nextToken();
            if (token != "/") {
                tokens.push(token);
            } else {
                string token2 = tokens.pop();
                token = scanner.nextToken();
                cout << "token=" << token << " token2=" << token2 << endl;
                if (token != token2) {
                    return false;
                }
            }
        }
        
//        cout << token << endl;
    }
    return true;
}



























