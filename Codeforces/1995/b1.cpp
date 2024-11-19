#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<long long> prefix(n + 1, 0ll);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; ++i) prefix[i] = 1ll * a[i] + prefix[i - 1];
    vector<int> index(n + 1);
    for (int i = 1; i <= n; ++i) {
        int lo = i;
        int hi = n;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (a[mid] <= a[i] + 1) lo = mid;
            else hi = mid - 1;
        }
        index[i] = lo;
    }
    auto range = [&] (int l, int r) -> long long {
        return prefix[r] - prefix[l - 1];
    };
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        int lo = i;
        int hi = index[i];
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (range(i, mid) <= m) lo = mid;
            else hi = mid - 1;
        }
        if (range(i, lo) <= m) ans = max(ans, range(i, lo)); 
    }
    cout << ans << "\n";
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
