#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, X; cin >> r >> X;
    if (X == 1) {
        cout << ((r >= 1600 && r <= 2999) ? "Yes" : "No");
    }
    else cout << ((r >= 1200 && r <= 2399) ? "Yes" : "No");
    return 0;
}
