#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int result = 0;
    for (int i = 30; i >= 0; --i) {
        if (n & (1 << i)) {
            result |= (1 << i);
            break;
        }
    }
    cout << result << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
