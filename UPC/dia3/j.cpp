#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        vector<int> pos;
        pos.emplace_back(0);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') pos.emplace_back(i + 1);
        }
        pos.emplace_back(n + 1);
        int ans = 0;
        for (int i = 1; i < pos.size(); ++i) {
            int dis = pos[i] - pos[i - 1] - 1;
            if (pos[i] == n + 1 && pos[i - 1] == 0) {
                dis += k;
                ans += (dis / (k + 1));
            }
            else if (pos[i] == n + 1) {
                ans += max(0, dis / (k + 1));
            }
            else if (pos[i - 1] == 0) {
                ans += max(0, dis / (k + 1));
            }
            else {
                dis -= k;
                ans += max(0, dis / (k + 1));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
