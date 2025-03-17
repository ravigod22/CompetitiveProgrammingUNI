#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        char c; cin >> c;
        string s; cin >> s;
        vector<int> pos;
        s = s + s;
        for (int i = 0; i < 2 * n; ++i) {
            if (s[i] == 'g') pos.emplace_back(i);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) {
                int ind = *lower_bound(pos.begin(), pos.end(), i);
                ans = max(ans, ind - i);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
