//
//  main.cpp
//  p5_reverse_string
//
//  Created by Ilya Rudyak on 1/16/16.
//  Copyright © 2016 Ilya Rudyak. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

string ReverseString(string s);

int main(int argc, const char * argv[]) {
    
    string s = "table";
    cout << ReverseString(s) << endl;
    return 0;
}


string ReverseString(string s, string acc) {
    
    cout << s << " " << acc << endl;
    if (s.size() <= 1) {
        return acc + s;
    } else {
        string scopy;
        return ReverseString(s.substr(0, s.size() - 1),
                             acc + s[s.size() - 1]);
    }
}

string ReverseString(string s) {
    return ReverseString(s, string());
}










