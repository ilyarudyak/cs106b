#include <iostream>
#include <vector>

using namespace std;

void printInBinary(int number) {

    if (number == 0) {
        return;
    }

    printInBinary(number / 2);
    cout << number % 2;

}


void subsets(string soFar, string rest) {
    if (rest.empty())
        cout << soFar << endl;
    else {
        subsets(soFar + rest[0], rest.substr(1)); // include first char
        subsets(soFar, rest.substr(1)); // exclude first char
    }
}
bool canMakeSum(string sacc, int acc, vector<int>& nums, int targetSum, int index) {

    if (index >= nums.size()) {
        cout << sacc << " " << acc << " " << to_string(acc == targetSum) << endl;
        return acc == targetSum;
    }

    return canMakeSum(sacc + to_string(nums[index]), acc + nums[index], nums, targetSum, index + 1) ||
           canMakeSum(sacc, acc, nums, targetSum, index + 1);

}
bool canMakeSum(vector<int>& nums, int targetSum) {
    return canMakeSum("", 0, nums, targetSum, 0);
}

void canMakeSum2(string sacc, int acc, vector<int>& nums, int targetSum, int index) {

    if (index >= nums.size()) {
        if (acc == targetSum) {
            cout << sacc << " " << acc << " " << to_string(acc == targetSum) << endl;
        }
        return;
    }

    canMakeSum2(sacc + to_string(nums[index]), acc + nums[index], nums, targetSum, index + 1);
    canMakeSum2(sacc, acc, nums, targetSum, index + 1);

}
void canMakeSum2(vector<int>& nums, int targetSum) {
    return canMakeSum2("", 0, nums, targetSum, 0);
}



int main() {

    vector<int> nums = {3, 7, 1, 8, -3};
//    cout << canMakeSum(nums, 4) << endl;
    canMakeSum2(nums, 4);

//    printInBinary(250);

    return 0;
}



















