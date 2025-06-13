#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int one = 0, cero = 0, tmp = 0;
    vector<int> suf(n + 1, 0), pre(n, 0);
    pre[0] = s[0] == '0';
    for (int i = 1; i < n; ++i) pre[i] = pre[i - 1] + (s[i] == '0');
    for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + (s[i] == '1');
    int ans = count(s.begin(), s.end(), '1');
    for (int i = 0; i < n; ++i) {
        ans = min(ans, suf[i + 1] + pre[i] + tmp);
        tmp = min(tmp, i + 1 - 2 * pre[i]);
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
