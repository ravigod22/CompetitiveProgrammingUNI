#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n, m; cin >> n >> m;
    vector<int> b(n), w(m);
    for (int& e : b) cin >> e;
    for (int& e : w) cin >> e;
    sort(b.rbegin(), b.rend());
    sort(w.rbegin(), w.rend());
    vector<i64> prefix(n, 0);
    for (int i = 0; i < n; ++i) prefix[i] = (i ? prefix[i - 1] : 0) + b[i];
    i64 acc = 0;
    auto f = [&] (int x) -> i64 {
        int lo = x;
        int hi = n - 1;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (b[mid] >= 0) lo = mid;
            else hi = mid - 1;
        }
        return prefix[lo];
    };
    i64 ans = max(0LL, f(0));
    for (int i = 0; i < min(n, m); ++i) {
        acc += w[i];
        ans = max(ans, acc + f(i));
    }
    cout << ans << "\n";
    return 0;
}

