#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool IsMeasurable(int t, set<int> & w);

int main(int argc, const char * argv[]) {
    
    set<int> w;
    w.insert(1);
//    w.insert(3);
    w.insert(5);
    
    for (int i = 1; i < 7; i++) {
        cout << "i=" << i << ":" << IsMeasurable(i, w) << " ";
    }
    cout << endl;
    
    return 0;
}


bool IsMeasurable(int t, set<int> &w) {
    
    bool result = false;
    if (w.size() == 1) {
        return t == *w.begin();
    } else {
    
        for (auto it = w.cbegin(); it != w.cend(); ++it) {
            set<int> w0 = w;
            w0.erase(*it);
            result =    result ||
                        IsMeasurable(t      , w0) ||
                        IsMeasurable(t + *it, w0) ||
                        IsMeasurable(t - *it, w0);
        }
    }
    
    return result;
}








































