#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        //cout << "----------------------------\n";
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        sort(a.rbegin(), a.rend());
        i64 remain = 0;
        i64 alice = 0;
        i64 bob = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) alice += a[i];
            else bob += a[i];
        }
        for (int i = 0; i < n; i += 2) {
            if (i + 1 < n) {
                remain += 1LL * (a[i] - a[i + 1]);
            }
        }
        //cout << alice << " " << bob << "\n";
        //cout << remain << "\n";
        bob += min(1LL * k, remain);
        cout << alice - bob << "\n";
    }
    return 0;
}

