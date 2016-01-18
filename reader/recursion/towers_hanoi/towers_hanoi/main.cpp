#include <iostream>
#include <stack>
using namespace std;

void towers(int n, char start, char finish, char tmp);

int main() {
    
    towers(3, 'A', 'B', 'C');
    return 0;
}


void towers(int n, char start, char finish, char tmp) {
    
    if (n == 0) {
        return;
    }
    
    towers(n - 1, start, tmp, finish);
    cout << start << "->" << finish << " " << endl;
    towers(n - 1, tmp, finish, start);
}























