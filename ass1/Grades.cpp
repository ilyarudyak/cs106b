#include <iostream>
#include <fstream>
#include "vector.h"
#include <algorithm>
#include <numeric>
using namespace std;

struct Grades {
    
    double min;
    double max;
    double average;
};


int main() {
    
    Grades grades;
    Vector<double> data;
    
    
    ifstream infile;
    infile.open("grades.txt");
    
    while (true) {
        double value;
        infile >> value;
        data.add(value);
        if (infile.fail()) break;
        
    }
    
    infile.close();
    
    grades.min = *min_element(begin(data), end(data));
    grades.max = *max_element(begin(data), end(data));
    grades.average = accumulate(data.begin(), data.end(), 0.0) / data.size();
    cout << "min=" << grades.min << endl;
    cout << "max=" << grades.max << endl;
    cout << "average=" << grades.average << endl;
    
    return 0;
}


















