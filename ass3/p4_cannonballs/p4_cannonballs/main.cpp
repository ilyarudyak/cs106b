//
//  main.cpp
//  p4_cannonballs
//
//  Created by Ilya Rudyak on 1/17/16.
//  Copyright © 2016 Ilya Rudyak. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int Cannonball(int height);

int main(int argc, const char * argv[]) {
    
    int height = 3;
    cout << Cannonball(height) << endl;
    
    return 0;
}

int Cannonball(int height) {
    
    if (height == 1) {
        return 1;
    }
    
    return pow(height, 2) + Cannonball(height - 1);
}