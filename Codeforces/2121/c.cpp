#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> r(n), c(m);
    int g[n][m];
    int maxe = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
            maxe = max(maxe, g[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            r[i] += (g[i][j] == maxe);
        }
        cnt += r[i];
    }
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            c[j] += (g[i][j] == maxe);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int tmp = c[j] + r[i] - (g[i][j] == maxe ? 1 : 0);
            if (tmp == cnt) {
                cout << maxe - 1 << "\n";
                return;
            }
        }
    }
    cout << maxe << "\n";
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


