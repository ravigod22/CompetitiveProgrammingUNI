#include <bits/stdc++.h>
using namespace std;

int a, b;

void solve() {
    cin >> a >> b;
    int tmp = abs(a - b);
    cout << (tmp + 9) / 10 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
