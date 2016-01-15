#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

vector<vector<bool> > read_file(ifstream &in);
vector<vector<int> > MakeGridOfCounts(vector<vector<bool> > &bms);

const int N = 6;

int main() {
    
    ifstream in;
    in.open("minesweeper.txt");
    vector<vector<bool> > bms = read_file(in);
    in.close();
    
    vector<vector<int> > ims = MakeGridOfCounts(bms);
    for (auto v : ims) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    
    return 0;
}

int count(vector<vector<bool> > &bms, int i, int j) {
    
    int result = 0;
    vector<bool> row_above(N, 0);
    vector<bool> row = bms[i];
    vector<bool> row_below(N, 0);
    int left = j, right = j;
    
    if (j == 0) {
        right = j + 1;
    } else if (j == N - 1) {
        left = j - 1;
    } else {
        left = j - 1;
        right = j + 1;
    }
        
    if (i == 0) {
        row_below = bms[i + 1];
    } else if (i == N - 1) {
        row_above = bms[i - 1];
    } else {
        row_above = bms[i - 1];
        row_below = bms[i + 1];
    }
    
    for (int k = left; k <= right; k++) {
        result += row_above[k];
        result += row[k];
        result += row_below[k];
    }
    
    return result;
}

vector<vector<int> > MakeGridOfCounts(vector<vector<bool> > &bms) {
    
    vector<vector<int> > ims;
    for (int i = 0; i < N; i++) {
        vector<int> row;
        for (int j = 0; j < N; j++) {
            row.push_back(count(bms, i, j));
        }
        ims.push_back(row);
    }
    return ims;
}

vector<vector<bool> > read_file(ifstream &in) {

    vector<vector<bool> > bms;
    vector<bool> row;
    int count1 = 0, count2 = 0;
    
    while (true) {
        if (count1 == N) {
            bms.push_back(row);
            row.clear();
            count1 = 0;
            count2++;
        }
        int ch = in.get();
        if (ch == EOF) {
            break;
        }
        
        char ch2 = (char) ch;
        
        if (ch2 == 'T') {
            row.push_back(true);
            count1++;
        } else if (ch2 == 'F') {
            row.push_back(false);
            count1++;
        }
    }
    return bms;
}






























