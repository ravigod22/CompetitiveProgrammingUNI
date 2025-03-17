#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        string s; cin >> s;
        i64 grid[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }
        vector<i64> col(m), row(n);
        for (int i = 0; i < n; ++i) {
            i64 sum = 0;
            for (int j = 0; j < m; ++j) {
                sum += grid[i][j];
            }
            row[i] = sum;
        }
        for (int j = 0; j < m; ++j) {
            i64 sum = 0;
            for (int i = 0; i < n; ++i) {
                sum += grid[i][j];
            }
            col[j] = sum;
        }
        int c = 0, r = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == 'D') {
                // update the row 
                grid[r][c] = -row[r];
                col[c] += grid[r][c];
                row[r] = 0;
                r++;
            }
            else {
                // update the col 
                grid[r][c] = -col[c];
                row[r] += grid[r][c];
                col[c] = 0;
                c++;
            }
        }
        grid[r][c] = -row[r];
        for (int i = 0; i < n; ++i) {
            i64 sum = 0;
            for (int j = 0; j < m; ++j) {
                sum += grid[i][j];
            }
            assert(sum == 0);
        }
        for (int j = 0; j < m; ++j) {
            i64 sum = 0;
            for (int i = 0; i < n; ++i) {
                sum += grid[i][j];
            }
            assert(sum == 0);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << grid[i][j] << " \n"[j + 1 == m];
            }
        }
    }
    return 0;
}


