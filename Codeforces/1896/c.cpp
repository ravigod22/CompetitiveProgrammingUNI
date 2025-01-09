#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, x; cin >> n >> x;
        vector<pair<int, int>> a;
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            a.emplace_back(x, i);
        }
        for (int& e : b) cin >> e;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        rotate(b.begin(), b.begin() + x, b.end());
        int can = 0;
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[a[i].second] = b[i];
            if (a[i].first > b[i]) can++;
        }
        if (can == x) {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
        }
        else cout << "NO\n";
    }
    return 0;
}
