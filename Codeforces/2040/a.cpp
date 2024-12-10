#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    if (n == 1) {
        cout << "YES\n";
        cout << 1 << "\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        bool can = true;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (abs(a[i] - a[j]) % k == 0) {
                can = false;
            }
        }
        if (can) {
            cout << "YES\n";
            cout << i + 1 << "\n";
            return;
        }
    }
    cout << "NO\n";
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
