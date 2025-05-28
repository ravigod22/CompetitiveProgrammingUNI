#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> mid, fle;
    for (int i = 1; i + 1 < n; ++i) {
        if (a[i - 1] < a[i] && a[i] > a[i + 1]) mid.push_back(i);
        if (a[i - 1] > a[i] && a[i] < a[i + 1]) fle.push_back(i);
    }
    mid.push_back(n - 1);
    fle.push_back(n - 1);
    i64 ans = 0;
    for (int i = 1; i + 2 < n; ++i) {
        auto itf = lower_bound(mid.begin(), mid.end(), i);
        auto its = lower_bound(fle.begin(), fle.end(), i);
        if (*itf == n - 1 or *its == n - 1) continue;
        if (a[i] <= a[i - 1]) continue;
        auto sigf = upper_bound(mid.begin(), mid.end(), *itf);
        auto sigs = upper_bound(fle.begin(), fle.end(), *its);
        int l = max(*its, *itf), r = min(*sigf, *sigs);
        ans += max(0LL, 0LL + r - l);
    }
    cout << ans << "\n";
    return 0;
}


