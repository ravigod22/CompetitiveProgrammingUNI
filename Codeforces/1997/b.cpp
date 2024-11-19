#include <bits/stdc++.h>
using namespace std;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        char a[2][n];
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 1; j < n - 1; ++j)
            if (a[i][j - 1] == '.' && a[i][j] == '.' && a[i][j + 1] == '.' && a[i ^ 1][j - 1] == 'x' && a[i ^ 1][j] == '.' && a[i ^ 1][j + 1] == 'x') {
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

