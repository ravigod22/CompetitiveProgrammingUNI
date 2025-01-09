#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        i64 ans = accumulate(a.begin(), a.end(), 0LL);
        i64 sum = 0;
        reverse(a.begin(), a.end());
        for (int i = 0; i + 1 < n; ++i) {
            sum += 1LL * a[i];
            if (sum >= 0) ans += sum;
        }
        cout << ans << "\n";
    }
    return 0;
}
