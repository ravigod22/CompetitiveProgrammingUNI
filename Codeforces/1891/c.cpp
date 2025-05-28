#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 step;

bool f(i64 lim, vector<int> a) {
    step = lim;
    i64 sum = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        sum += a[i];
        if (sum < lim) {
            a[i] = 0;
        }
        else {
            a[i] = sum - lim;
            break;
        }
    }
    for (int i = 0; i < (int)a.size(); ++i) {
        if (!a[i]) continue;
        lim -= a[i];
        if (lim >= 0) {
            step++;
        }
        else {
            return false;
        }
    }
    return true;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    i64 lo = 1;
    i64 hi = accumulate(a.begin(), a.end(), 0LL);
    while (lo < hi) {
        i64 mid = (lo + hi) / 2;
        if (f(mid, a)) hi = mid;
        else lo = mid + 1;
    }
    i64 res = f(lo, a);
    cout << step << "\n";
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
