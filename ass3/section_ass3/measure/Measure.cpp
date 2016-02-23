//
// Created by Ilya Rudyak on 2/23/16.
//

#include "Measure.h"
#include <vector>
using namespace std;

Measure::Measure(vector<int> weights) {
    this->weights = weights;
}

bool Measure::isMeasurable(int target) {
    return isMeasurable(target, weights);
}

bool Measure::isMeasurable(int target, vector<int> remWeights) {
    if (remWeights.empty()) {
        return target == 0;
    } else {

        int weight = *remWeights.begin();
        vector<int> remWeights2 = remWeights;
        remWeights2.erase(remWeights2.begin());

        return isMeasurable(target + weight, remWeights2) ||
               isMeasurable(target - weight, remWeights2) ||
               isMeasurable(target, remWeights2);
    }
}
