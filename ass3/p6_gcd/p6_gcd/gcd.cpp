//
//  main.cpp
//  p6_gcd
//
//  Created by Ilya Rudyak on 1/16/16.
//  Copyright © 2016 Ilya Rudyak. All rights reserved.
//

#include <iostream>
using namespace std;

int GCD(int x, int y);

int main(int argc, const char * argv[]) {

    cout << GCD(54, 24) << endl;
    return 0;
}


int GCD(int x, int y) {
    
    if (x % y == 0) {
        return y;
    } else {
        return GCD(y, x % y);
    }
    return 0;
}
