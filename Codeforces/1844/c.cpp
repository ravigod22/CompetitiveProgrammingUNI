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
        vector<int> c(n);
        for (int& e : c) cin >> e;
        i64 maxe1 = -1e9, maxe2 = -1e9;
        i64 sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                maxe1 = max(maxe1, 1LL * c[i]);
                sum1 += max(0LL, 1LL * c[i]);
            }
            else {
                maxe2 = max(maxe2, 1LL * c[i]);
                sum2 += max(0LL, 1LL * c[i]);
            }
        }
        if (maxe1 < 0) sum1 = maxe1;
        if (maxe2 < 0) sum2 = maxe2;
        cout << max(sum1, sum2) << "\n";
    }
    return 0;
}

