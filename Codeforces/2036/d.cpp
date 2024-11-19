#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


const int dx[] = {1, 1, -1, -1};
const int dy[] = {1, -1, -1, 1};

void solve() {
    int n, m; cin >> n >> m;
    char grid[n][m];
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    int x[4], y[4];
    x[0] = y[0] = 0;
    x[1] = 0;
    y[1] = m - 1;
    x[2] = n - 1;
    y[2] = m - 1;
    x[3] = n - 1;
    y[3] = 0;
    int ans = 0;
    while (x[0] < x[3] && y[0] < y[1]) {
        string s;
        for (int k = 0; k < 4; ++k) {
            if (k == 0) {
                for (int j = y[k]; j <= y[(k + 1) % 4]; ++j) {
                    s += grid[x[k]][j]; 
                } 
            }
            else if (k == 1) {
                for (int i = x[k]; i <= x[(k + 1) % 4]; ++i) {
                    s += grid[i][y[k]];
                }
            }
            else if (k == 2) {
                for (int j = y[k]; j >= y[(k + 1) % 4]; --j) {
                    s += grid[x[k]][j];
                }
            }
            else {
                for (int i = x[k]; i >= x[(k + 1) % 4]; --i) {
                    s += grid[i][y[k]];
                }
            }
            s.pop_back();
        }
        for (int i = 0; i < 3; ++i) s += s[i];
        for (int i = 0; i + 3 < (int)s.size(); ++i) {
            // 1543
            if (s[i] == '1' && s[i + 1] == '5' && s[i + 2] == '4' && s[i + 3] == '3') ans++; 
        }
        for (int i = 0; i < 4; ++i) {
            x[i] += dx[i];
            y[i] += dy[i];
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


