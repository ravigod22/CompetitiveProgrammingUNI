#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> cnt(26, 0);
        for (int i = 0; i < n; ++i) {
            cnt[s[i] - 'a']++;
        }
        string ans;
        while (ans.size() != n) {
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] == 0) continue;
                ans += 'a' + i;
                cnt[i]--;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
