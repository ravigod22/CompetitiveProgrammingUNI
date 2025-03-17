#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<i64> a(n);
        for (auto& e : a) cin >> e;
        i64 lim = -1e16;
        for (int i = 0; i + 1 < n; ++i) {
            i64 &x = a[i], &y = a[i + 1];
            i64 aux = lim - x;
            x += aux;
            y += aux;
        }
        bool can = true;
        for (int i = 1; i < n; ++i) {
            if (a[i - 1] > a[i]) can = false;
        }
        cout << (can ? "YES" : "NO") << "\n";
    }
    return 0;
}

