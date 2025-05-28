#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n, m; cin >> n >> m;
    int grid[n][m];
    int a[n], b[n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    int aux[n][m];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            aux[i][j] = grid[i][j];
    i64 acc = 0;
    for (int i = 1; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < m; ++j) {
            if (aux[i][j] == aux[i - 1][j]) cnt++;
        }
    }
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


