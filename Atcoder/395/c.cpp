#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

const int maxn = 1e6 + 5;
vector<int> pos[maxn];

void solve() {
    int n; cin >> n;
    int ans = n + 1;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    for (int i = 1; i < maxn; ++i) {
        if (pos[i].size() < 2) continue;
        vector<int> tmp = pos[i];
        for (int j = 1; j < (int)tmp.size(); ++j) {
            ans = min(ans, tmp[j] - tmp[j - 1] + 1);
        }
    }
    if (ans == n + 1) ans = -1;
    cout << ans << "\n";
    for (int i = 0; i < n; ++i) {
        if (!pos[a[i]].empty()) pos[a[i]].clear();
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
