#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        char grid[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }
        vector<string> tmp;
        for (int i = 0; i < n; i += k) {
            string aux;
            for (int j = 0; j < n; j += k) {
                aux += grid[i][j];
            }
            tmp.emplace_back(aux);
        }
        for (string s : tmp) {
            cout << s << "\n";
        }
    }
    return 0;
}
