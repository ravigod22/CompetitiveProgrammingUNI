#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<pair<int, int>> a;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if (x % k == 0) a.emplace_back(k, -i);
            else a.emplace_back(x % k, -i);
        }
        sort(a.rbegin(), a.rend());
        for (int i = 0; i < n; ++i) cout << abs(a[i].second) + 1 << " \n"[i + 1 == n];
    }
    return 0;
}


