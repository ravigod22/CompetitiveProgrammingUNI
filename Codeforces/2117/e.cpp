#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for (int& e : p) cin >> e;
    for (int& e : q) cin >> e;
    vector<int> f, s;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            f.push_back(p[i]);
            s.push_back(q[i]);
        }
        else {
            s.push_back(p[i]);
            f.push_back(q[i]);
        }
    }
    // pv(f);
    // pv(s);
    vector<int> pos[2][n + 1];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        pos[0][f[i]].push_back(i);
    }
    for (int j = 0; j < n; ++j) {
        pos[1][s[j]].push_back(j);
    }
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(pos[1][f[i]].begin(), pos[1][f[i]].end(), i);
        if (it == pos[1][f[i]].end()) continue;
        ans = max(ans, i + 1);
    }
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(pos[0][s[i]].begin(), pos[0][s[i]].end(), i);
        if (it == pos[0][s[i]].end()) continue;
        ans = max(ans, i + 1);
    }
    for (int i = 1; i <= n; ++i) {
        auto v = pos[0][i];
        if (v.size() < 2) continue;
        for (int j = 1; j < (int)v.size(); ++j) {
            int res = v[j] - v[j - 1];
            if (res > 1) ans = max(ans, v[j - 1] + 1);
            else {
                if (j > 1) {
                    ans = max(ans, v[j - 2] + 1);
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        auto v = pos[1][i];
        if (v.size() < 2) continue;
        for (int j = 1; j < (int)v.size(); ++j) {
            int res = v[j] - v[j - 1];
            if (res > 1) ans = max(ans, v[j - 1] + 1);
            else {
                if (j > 1) ans = max(ans, v[j - 2] + 1);
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


