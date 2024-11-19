#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    if (n == 3) {
        if (a[0] == a[1] && a[0] == a[2]) cout << "NO\n";
        else {
            cout << "YES\n";
            cout << "RBR\n";
        }
        return;
    }
    if (a[0] != a[n - 1]) {
        if (a[n - 1] - a[0] == a[n - 2] - a[1]) {
            cout << "YES\n";
            for (int i = 0; i < n - 1; ++i) cout << "R";
            cout << "B";
        }
        else {
            cout << "YES\n";
            cout << "R";
            for (int i = 1; i < n - 1; ++i) cout << "B";
            cout << "R";
        }
        cout << "\n";
    }
    else cout << "NO\n";
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
