#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        char grid[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                vector<char> aux = {grid[i][j], grid[j][n - i - 1], grid[n - i - 1][n - j - 1], grid[n - j - 1][i]};
                char tmp = *max_element(aux.begin(), aux.end());
                for (auto e : aux) ans += tmp - e;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
