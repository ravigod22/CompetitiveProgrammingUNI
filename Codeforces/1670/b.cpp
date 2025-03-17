#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        int k; cin >> k;
        vector<bool> special(26, 0);
        for (int i = 0; i < k; ++i) {
            char c; cin >> c;
            special[c - 'a'] = 1;
        }
        int ans = -1;
        int last = 0;
        for (int i = 0; i < n; ++i) {
            if (!special[s[i] - 'a']) continue;
            ans = max(ans, i - last - 1);
            last = i;
        }
        cout << ans + 1 << "\n";
    }
    return 0;
}
