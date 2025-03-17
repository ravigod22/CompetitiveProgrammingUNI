#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, x; cin >> n >> x;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        int cnt = 0;
        i64 l = a[0] - x, r = a[0] + x;
        for (int i = 1; i < n; ++i) {
            i64 li = a[i] - x, ri = a[i] + x;
            if (r < li or ri < l) {
                cnt++;
                l = li, r = ri;
            }
            else {
                l = max(l, li);
                r = min(r, ri);
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
