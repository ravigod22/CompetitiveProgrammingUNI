#include <bits/stdc++.h>
using namespace std;

long long n, k;

void solve() {
    cin >> n >> k;
    long long lo = k;
    long long hi = k + n - 1;
    auto sum = [&] (long long l, long long r) {
        return r * (r + 1) / 2 - l * (l - 1) / 2;
    };
    long long ans = 0;
    while (lo < hi) {
        long long mid = (lo + hi) / 2;
        if (sum(k, mid) - sum(mid + 1, k + n - 1) >= 0) hi = mid;
        else lo = mid + 1;
    }
    if (sum(k, lo) - sum(lo + 1, k + n - 1) >= 0) ans = sum(k, lo) - sum(lo + 1, k + n - 1);
    lo = k;
    hi = k + n - 1;
    while (lo < hi) {
        long long mid = (lo + hi + 1) / 2;
        if (sum(k, mid) - sum(mid + 1, k + n - 1) <= 0) lo = mid;
        else hi = mid - 1;
    }
    if (sum(k, lo) - sum(lo + 1, k + n - 1) <= 0) ans = min(ans, abs(sum(k, lo) - sum(lo + 1, k + n - 1)));
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

