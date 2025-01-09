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
        vector<int> a(n);
        for (int& e : a) cin >> e;
        int maxe = *max_element(a.begin(), a.end());
        auto solve = [&] (int target) -> i64 {
            vector<int> remain = a;
            for (int& e : remain) e = target - e;
            i64 sum = accumulate(remain.begin(), remain.end(), 0LL);
            i64 lo = 0;
            i64 hi = 1e18;
            while (lo < hi) {
                i64 mid = (lo + hi) / 2;
                i64 ones = (mid + 1) / 2;
                i64 twos = mid / 2;
                i64 acc = sum;
                for (int e : remain) {
                    if (1LL * e / 2 <= twos) {
                        twos -= 1LL * e / 2;
                        acc -= 2LL * (e / 2);
                    }
                    else {
                        acc -= twos * 2;
                        break;
                    }
                }
                if (acc <= ones) hi = mid;
                else lo = mid + 1;
            }
            return lo;
        };
        cout << min(solve(maxe), solve(maxe + 1)) << "\n";
    }
    return 0;
}
