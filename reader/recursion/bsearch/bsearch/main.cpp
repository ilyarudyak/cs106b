#include <iostream>
#include <vector>
using namespace std;

int bin_search(vector<int> v, int target);

int main(int argc, const char * argv[]) {
    
    vector<int> v = {1, 2, 3, 4, 5, 10, 20, 30};
    cout << bin_search(v, 20) << endl;
    
    return 0;
}

int bin_search(vector<int> v, int target, int left, int right) {
    
    if (left > right) {
        return -1;
    }
    
    int med = left + (right - left) / 2;
    if (target == v[med]) {
        return med;
    } else if (target > v[med]) {
        return bin_search(v, target, med + 1, right);
    } else {
        return bin_search(v, target, left, med - 1);
    }
}

int bin_search(vector<int> v, int target) {
    return bin_search(v, target, 0, v.size() - 1);
}
























