//
// Created by Ilya Rudyak on 5/26/16.
//

#ifndef ASS3_V3_MEASURER_H
#define ASS3_V3_MEASURER_H

#include <vector>
#include <stack>
using namespace std;

class Measurer {
public:
    Measurer(string measures) {
        this->measures = measures;
    }

    bool isMeasurable(int weight) {
        return isMeasurable(weight, measures);
    }

private:
    string measures;
    bool isMeasurable(int weight, string weights) {
        if (weights.empty()) {
            return weight == 0;
        }

        return isMeasurable(weight - (weights[0] - '0'), weights.substr(1)) ||
               isMeasurable(weight                     , weights.substr(1)) ||
               isMeasurable(weight + (weights[0] - '0'), weights.substr(1));
    }
};

#endif //ASS3_V3_MEASURER_H
