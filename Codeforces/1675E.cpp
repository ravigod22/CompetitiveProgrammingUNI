#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> mp(26);
    iota(mp.begin(), mp.end(), 0);
    int maxe = 0;
    int lim = 0;
    for (int i = 0; i < n; ++i) {
        lim = max(lim, s[i] - 'a');
    }
    k = min(k, lim);
    for (int i = 0; i < n; ) {
        while (i < n && max(maxe, s[i] - 'a') <= k) {
            maxe = max(maxe, s[i] - 'a');
            ++i;
        }
        for (int j = 0; j <= maxe; ++j) mp[j] = 0;
        if (i == n) break;
        k -= maxe;
        int remain = s[i] - 'a';
        for (int j = remain; j >= remain - k; --j) mp[j] = remain - k;
        break;
    }
    for (int i = 0; i < n; ++i) s[i] = char(mp[s[i] - 'a'] + 'a');
    cout << s << "\n";
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
