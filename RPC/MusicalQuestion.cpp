#include <bits/stdc++.h>
using namespace std;

void solve() {
    cout << fixed << setprecision(8);
    int x, y;
    cin >> x >> y;
    if (x == y) {
        cout << 1.0;
    }
    else if (x < y) {
        double tmp = 1.0 *(y - x);
        cout << tmp / (1.0 * y);
    }
    else {
        double tmp = 1.0 * (x - y);
        cout << (1.0 * x )/ tmp; 
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
