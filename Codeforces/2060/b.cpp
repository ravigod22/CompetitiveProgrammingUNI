#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n, m; cin >> n >> m;
    vector<int> card[n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x; cin >> x;
            card[i].emplace_back(x);
        }
        sort(card[i].begin(), card[i].end());
    }
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        v.emplace_back(card[i][0], i);
    }
    sort(v.begin(), v.end());
    vector<int> per(n);
    for (int i = 0; i < n; ++i) per[i] = v[i].second;
    int init = -1;
    bool can = true;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int cur = card[per[j]][i];
            if (init < cur) {
                init = cur;
            }
            else {
                can = false;
                break;
            }
        }
        if (!can) break;
    }
    if (can) {
        for (int i = 0; i < n; ++i) cout << per[i] + 1 << " \n"[i + 1 == n];
    }
    else cout << -1 << "\n";
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


