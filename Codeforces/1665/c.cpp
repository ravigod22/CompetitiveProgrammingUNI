#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> cnt(n + 1, 0);
    for (int i = 1; i < n; ++i) {
        int p; cin >> p;
        cnt[--p]++;
    }
    vector<int> child;
    child.emplace_back(1);
    for (int i = 0; i < n; ++i) {
        if (cnt[i]) child.emplace_back(cnt[i]);
    }
    sort(child.rbegin(), child.rend());
    auto f = [&] (int t) -> bool {
        if (t < (int)child.size()) return 0;
        i64 sum = 0;
        for (int i = 0; i < (int)child.size(); ++i) {
            sum += max(0LL, 0LL + child[i] - t + i);
        }
        return sum <= 1LL * t - (i64)child.size();
    };
    int lo = 1;
    int hi = 2e5 + 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (f(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << "\n";
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
