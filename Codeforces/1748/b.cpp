#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int pre[n][10];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            int tmp = s[i] - '0';
            pre[i][j] = (i ? pre[i - 1][j] : 0) + (tmp == j);
        }
    }
    auto f = [&] (int l, int r, int op) -> int {
        return pre[r][op] - (l ? pre[l - 1][op] : 0);
    };
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < min(i + 100, n); ++j) {
            int maxe = 0;
            for (int k = 0; k < 10; ++k) {
                if (f(i, j, k) > 0) maxe++;
            }
            bool can = true;
            for (int k = 0; k < 10; ++k) {
                if (f(i, j, k) > maxe) can = false;
            }
            ans += can;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
