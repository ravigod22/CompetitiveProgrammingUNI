#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int m[n][n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> m[i][j];
        vector<int> a(n, 0);
        int ans[n][n];
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i < n; ++i) {
            int tmp = (1 << 30) - 1;
            for (int j = 0; j < n; ++j) {
                if (j == i) continue;
                tmp &= m[i][j];
            }
            a[i] = tmp;
        }
        bool res = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (m[i][j] != (a[i] | a[j])) res = false;
            }
        }
        cout << (res ? "YES" : "NO") << "\n";
        if (res) {
            for (int i = 0; i < n; ++i) cout << a[i] << " \n"[i + 1 == n];
        }
    }
    return 0;
}
