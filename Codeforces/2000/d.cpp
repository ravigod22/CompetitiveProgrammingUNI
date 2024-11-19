#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        vector<i64> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + a[i];
        string s; cin >> s;
        int fL = n - 1;
        int lR = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'L') fL = min(i, fL);
            else lR = max(i, lR);
        }
        i64 ans = 0;
        for (int i = fL, j = lR; i < j; ) {
            if (s[i] == 'L' && s[j] == 'R') {
                ans += prefix[j + 1] - prefix[i];
                ++i;
                --j;
            }
            if (s[i] == 'R') ++i;
            if (s[j] == 'L') --j;
        }
        cout << ans << "\n";
    }
    return 0;
}
