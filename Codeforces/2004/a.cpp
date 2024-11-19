#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        if (n >= 3) {
            cout << "NO\n";
            continue;
        }
        if (a[1] - a[0] > 1) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
    return 0;
}
