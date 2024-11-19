#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        int a[n][m];
        map<int, pair<int, int>> pos;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        if (n == 1 && m == 1) {
            cout << -1 << "\n";
            continue;
        }
        int k = n * m + 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((a[i][j] + 1) % k == 0) {
                    a[i][j] = 1;
                }
                else {
                    a[i][j]++;
                }
                cout << a[i][j] << " \n"[j + 1 == m];
            }
        }
    }
    return 0;
}
