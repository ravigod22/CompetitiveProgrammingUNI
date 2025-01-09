#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x; cin >> x;
    cout << (x % 33 == 0 ? "YES" : "NO") << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
