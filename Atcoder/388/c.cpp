#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    sort(a.begin(), a.end());
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        int it = lower_bound(a.begin(), a.end(), 2 * a[i]) - a.begin();
        ans += 1LL * n - it;
    }
    cout << ans << "\n";
    return 0;
}
