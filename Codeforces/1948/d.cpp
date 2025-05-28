#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        string s; cin >> s;
        int n = s.size();
        int ans = 0;
        for (int i = 1; i <= n / 2; ++i) {
            vector<int> pre(n, 0);
            for (int j = 0; j + i < n; ++j) {
                if ((s[j] == '?') || (s[j + i] == '?') || (s[j] == s[j + i])) {
                    pre[j] = 1;
                }
            }
            for (int j = 1; j < n; ++j) pre[j] += pre[j - 1];
            int dis = i;
            for (int j = dis - 1; j < n; ++j) {
                int sum = pre[j] - (j - dis < 0 ? 0 : pre[j - dis]);
                if (sum == dis) ans = max(ans, dis);
            }
        }
        cout << 2 * ans << "\n";
    }
    return 0;
}
