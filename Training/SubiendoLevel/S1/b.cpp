#include <bits/stdc++.h>
using namespace std;
int n;

void solveHanoi(int init, int remain, int ending, int ndisks) {
    if (ndisks == 0) return;
    solveHanoi(init, ending, remain, ndisks - 1);
    cout << init << " " << ending << "\n";
    solveHanoi(remain, init, ending, ndisks - 1);
}

int main() {
    cin >> n;
    cout << (1 << n) - 1 << "\n";
    solveHanoi(1, 2, 3, n);
    return 0;
}
