
#include <iostream>
#include <set>
using namespace std;

bool subset_sum(set<int> &s, int target);
int subset_sum2(set<int> &s, int target);

int main() {
    
    set<int> s = {1, 2, 3, 4, 5, 10};
    int target = 5;
    cout << subset_sum2(s, target) << endl;
    return 0;
}

int subset_sum2(set<int> &s, int target) {
    
    if (s.empty()) {
        if (target == 0) {
            return 1;
        } else {
            return 0;
        }
    } else {
        int first = *(s.begin());
        set<int> rest = s;
        rest.erase(first);
        return  subset_sum2(rest, target) +
                subset_sum2(rest, target - first);
    }
}

void print_set(set<int> s) {
    for(auto n: s) {
        cout << n << " ";
    }
//    cout << endl;
}

bool subset_sum(set<int> &s, int target) {
    
    bool res = false;
    if (s.size() == 1) {
        
        if (s.count(10)) {
//            print_set(s);
//            cout << "target=" << target;
        }
            
        set<int>::iterator it = s.begin();
        if (s.count(10)) {
//            cout << " " << *it << endl;
        }
        
        if (target == *it) {
            return true;
        }
    }
    
    for (auto n: s) {
        set<int> s2 = s;
        s2.erase(n);
        
        if (s2.count(10)) {
//            print_set(s2);
//            cout << "target=" << target<< endl;
        }
        
        res = res || subset_sum(s2, target - n) || subset_sum(s2, target);
    }
    return res;

}
