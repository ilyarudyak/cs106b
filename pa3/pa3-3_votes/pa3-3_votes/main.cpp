

#include <iostream>
#include <vector>
#include <set>
using namespace std;


/*
 *   blocks - vector of block vote counts,
 *   blockIndex - index within that vector. The 
 *
 *   function counts the number of election
 *   outcomes in which the block at the index 
 *   has a critical vote.
 *
 */

int subsetSum(vector<int> &blocks, int bi, int majority);

int main() {
    
    vector<int> blocks = {4,2,7,4};
    int majority = 9;
    cout << subsetSum(blocks, 2, majority) << endl;
    
    return 0;
}

void printSet(set<int> &solution) {
    for (auto n: solution) {
        cout << n << " ";
    }
    cout << endl;
}

void printVector(vector<int> &v) {
    for (auto n: v) {
        cout << n << " ";
    }
    cout << endl;
}

int subsetSum(vector<int> &blocks, int b, int majority,
                int sumSoFar, int i, set<int> subset) {
    
    if (sumSoFar < majority && sumSoFar + b >= majority) {
        printSet(subset);
        return 1;
    }
    
    if (i == blocks.size()) {
        return 0;
    }
    
    set<int> subset1 = subset;
    subset1.insert(blocks[i]);
    
    return  subsetSum(blocks, b, majority,
                      sumSoFar, i + 1, subset) +
            subsetSum(blocks, b, majority,
                      sumSoFar + blocks[i], i + 1, subset1);
}

int subsetSum(vector<int> &blocks, int bi, int majority) {
    int b = blocks[bi];
    vector<int> blocks1 = blocks;
    blocks1.erase(blocks1.begin() + bi);
//    printVector(blocks1);
    return subsetSum(blocks1, b, majority, 0, 0, set<int>());
}

































