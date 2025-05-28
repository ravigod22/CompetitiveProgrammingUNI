#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    int grid[n + 1][m + 1];
    if (n % k == 0) {
        for (int j = 0; j < m; ++j) {
            int init = j % k;
            for (int i = 0; i < n; i += k) {
                int cnt = init;
                for (int a = i; a < i + k; ++a) {
                    grid[a][j] = cnt;
                    cnt = (cnt + 1) % k;
                }
            }
        }
    }
    else if (m % k == 0) {
        for (int i = 0; i < n; ++i) {
            int init = i % k;
            for (int j = 0; j < m; j += k) {
                int cnt = init;
                for (int b = j; b < j + k; ++b) {
                    grid[i][b] = cnt;
                    cnt = (cnt + 1) % k;
                }
            }
        }
    }
    else {
        int row = gcd(n, k);
        int col = k / row;
        for (int i = 0; i < n; i += row) {
            for (int j = 0; j < m; j += col) {
                int init = 0;
                for (int a = i; a < i + row; ++a) {
                    for (int b = j; b < j + col; ++b) {
                        grid[a][b] = init;
                        init = (init + 1) % k;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            grid[i][j]++;
            cout << grid[i][j] << " \n"[j + 1 == m];
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


