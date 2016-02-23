#ifndef SECTION_ASS3_MEASURE_H
#define SECTION_ASS3_MEASURE_H


#include <vector>
using namespace std;

class Measure {

public:
    Measure(vector<int> weights);

    bool isMeasurable(int target);

private:
    vector<int> weights;
    bool isMeasurable(int target, vector<int> remWeights);
};


#endif //SECTION_ASS3_MEASURE_H
























