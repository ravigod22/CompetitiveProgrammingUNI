#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        int a[n][m];
        int b[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> b[i][j];
            }
        }

        // row
        map<int,int> row;
        map<int,int> col;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                row[a[i][j]] = i + 1; 
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                col[a[j][i]] = i + 1;
            }
        }
        bool could = true;
        for (int i = 0; i < n; ++i) {
            set<int> s;
            for (int j = 0; j < m; ++j) {
                s.emplace(row[b[i][j]]);
            }
            if (s.size() != 1) could = false;
            s.clear();
        }
        for (int i = 0; i < m; ++i) {
            set<int> s;
            for (int j = 0; j < n; ++j) {
                s.emplace(col[b[j][i]]);
            }
            if (s.size() != 1) could = false;
            s.clear();
        }
        cout << (could ? "YES\n" : "NO\n");
    }
    return 0;
}
