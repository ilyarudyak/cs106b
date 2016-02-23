
#include <iostream>
#include <vector>
#include <set>
using namespace std;

void printInBinary(int number);
bool subsetSum(set<int> &nums, int target);
int subsetSum2(set<int> &nums, int target);
bool subsetSum3(vector<int> &nums, int targetSum);
void printSet(set<int> &solution);

int main() {
    
    vector<int> nums = {9, 3, 7, 1, 8, -3, 2};
    int target1 = 4;

    cout << subsetSum3(nums, target1) << endl;

    
    return 0;
}

void printSet(set<int> &solution) {
    for (auto n: solution) {
        cout << n << " ";
    }
    cout << endl;
}

bool subsetSum3(vector<int> &nums, int index,
                int sumSoFar, int target, set<int> subset) {
    
    if (sumSoFar == target) {
        printSet(subset);
        return true;
    }
    
    if (index == nums.size()) {
        return false;
    }
    
    set<int> subset1 = subset;
    subset1.insert(nums[index]);
    
    return  subsetSum3(nums, index + 1, sumSoFar, target, subset) ||
            subsetSum3(nums, index + 1, sumSoFar + nums[index], target, subset1);
}

bool subsetSum3(vector<int> &nums, int targetSum) {
    return subsetSum3(nums, 0, 0, targetSum, set<int>());
}

int subsetSum2(set<int> &nums, int target) {
    
    if (nums.empty()) {
        if (target == 0) {
            return 1;
        } else {
            return 0;
        }
    }
    
    int first = *(nums.begin());
    set<int> rest = nums;
    rest.erase(first);
    
    return subsetSum2(rest, target) + subsetSum2(rest, target - first);
}

bool subsetSum(set<int> &nums, int target) {
    
    if (nums.empty()) {
        return target == 0;
    }
    
    int first = *(nums.begin());
    set<int> rest = nums;
    rest.erase(first);
    
    return  subsetSum(rest, target) ||
            subsetSum(rest, target - first);
}

void printInBinary(int number) {
    
    if (number == 0) {
        return;
    }
    
    printInBinary(number / 2);
    cout << number % 2;
}
















