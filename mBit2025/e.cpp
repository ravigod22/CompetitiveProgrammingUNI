#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> b = a;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
        mp[a[i]].push_back(i);
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int ans = 1;
    for (int i = 0; i < b.size(); ++i) {
        int last = -1;
        int cnt = 0;
        for (int j = b[i]; j < 2e9; j += b[i]) {
            if (!mp.count(j)) break;
            auto it = upper_bound(mp[j].begin(), mp[j].end(), last);
            if (it == mp[j].end()) break;
            last = *it;
            cnt += 1;
        }
        ans = max(ans, cnt);
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
