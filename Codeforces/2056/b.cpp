#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    int grid[n][n];
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < n; ++j) {
            if (s[j] == '1') grid[i][j] = 1;
            else grid[i][j] = 0;
        }
    }
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 0);
    for (int i = 0; i < n; ++i) {
        vector<int> before, next, newans;
        int pos = find(ans.begin(), ans.end(), i) - ans.begin();
        for (int j = 0; j < pos; ++j) before.emplace_back(ans[j]);
        for (int j = pos; j < n; ++j) {
            if (ans[j] <= i || grid[i][ans[j]]) next.emplace_back(ans[j]);
            else before.emplace_back(ans[j]);
        }
        ans.clear();
        for (int e : before) ans.emplace_back(e);
        for (int e : next) ans.emplace_back(e);
    }
    for (int e : ans) {
        cout << e + 1 << " ";
    }
    cout << endl;
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


