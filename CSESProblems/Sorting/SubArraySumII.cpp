#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    vector<i64> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }
    map<i64, int> cnt;
    cnt[0] = 1;
    i64 ans = 0;
    for (int i = 1; i <= n; ++i) {
        i64 remain = pref[i] - 1LL * x;
        if (cnt.count(remain)) ans += cnt[remain];
        cnt[pref[i]]++;
    }
    cout << ans << "\n";
    return 0;
}
