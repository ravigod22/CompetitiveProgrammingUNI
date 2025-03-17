#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    // cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<i64> prefix(n + 1, 0);
        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + (s[i] == '1' ? i + 1 : 0);
            cnt[i + 1] = cnt[i] + (s[i] == '1');
        }
        i64 ans = 1e18;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                i64 left_one = cnt[i];
                i64 right_one = cnt[n] - cnt[i + 1];
                i64 left = left_one * (i + 1) - (left_one * (left_one + 1)) /2 - prefix[i];
                i64 right = prefix[n] - prefix[i + 1] - right_one * (i + 1) - (right_one * (right_one + 1)) / 2;
                ans = min(ans, left + right);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}



