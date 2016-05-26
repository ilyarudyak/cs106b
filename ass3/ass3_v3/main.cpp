#include <iostream>
#include "ListMnemonics.h"
#include "Measurer.h"

using namespace std;

int main() {

    // test Measurer
    Measurer measurer("13");
    cout << measurer.isMeasurable(2) << endl;
    cout << measurer.isMeasurable(4) << endl;
    cout << measurer.isMeasurable(5) << endl;


    // test ListMnemonics
//    ListMnemonics lm;
//    lm.list("723");



    return 0;
}