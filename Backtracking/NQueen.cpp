// This program gives first possible combination of NQueen solution
// to the n number of queens.

#include <__msvc_all_public_headers.hpp>
using namespace std;

int n = 4;
int v[4][4] = {0};

bool isSafe(int row, int col) {
    for (int ro = 0; ro < row ; ro++) {
        if (v[ro][col]) return false;
        if (v[ro][col - (row - ro)] && (col - (row - ro)) >= 0 ) return false;
        if (v[ro][col + (row - ro)] && (col + (row - ro)) <= row) return false;
    }
    return true;
}

bool place(int row) {
    if (row == n) return true;

    for (int co = 0; co < n; co++) {
        if (isSafe(row, co)){
            v[row][co] = 1;
            if (place(row+1)) return true;
            v[row][co] = 0;
        }
    }
    return false;
}

int main() {

    if (place(0)) {
        for (int x = 0;x < 4;x++) {
            for (int y = 0; y < 4; y++) {
                cout<<v[x][y]<<" ";
            }
            cout<<"\n";
        }
    }
    else cout<<"No Nqueen can happen";

    return 0;
}
