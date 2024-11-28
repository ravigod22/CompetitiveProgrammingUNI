#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


int main() {
    i64 k; cin >> k;
    vector<pair<i64, int>> pr;
    i64 tmp = k;
    for (int i = 2; 1LL * i * i <= k; ++i) {
        if (tmp % i == 0) {
            int cnt = 0;
            while (tmp % i == 0) {
                tmp /= i;
                cnt++;
            }
            pr.emplace_back(i, cnt);
        }
    }
    if (tmp > 1) pr.emplace_back(tmp, 1);
    auto f = [&] (i64 n) -> bool {
        for (auto [v, cnt] : pr) {
            i64 tmp = n;
            i64 aux = 0;
            while (tmp) {
                aux += tmp / v;
                tmp /= v;
            }
            if (aux < cnt) return 0;
        }
        return 1;
    };
    i64 lo = 1;
    i64 hi = 1e18;
    while (lo < hi) {
        i64 mid = (lo + hi) / 2;
        if (f(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << "\n";
    return 0;
}
