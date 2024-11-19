#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        int G[n][m];
        int R[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j){
                char x; cin >> x;
                G[i][j] = x - '0';
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char x; cin >> x;
                R[i][j] = x - '0';
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (G[i][j] == R[i][j]) continue;
                if ((G[i][j] + 2) % 3 == R[i][j]) {
                    G[i][j] = (G[i][j] + 2) % 3;
                    G[0][0] = (G[0][0] + 2) % 3;
                    G[0][j] = (G[0][j] + 1) % 3;
                    G[i][0] = (G[i][0] + 1) % 3;
                }
                else if ((G[i][j] + 1) % 3 == R[i][j]) {
                    G[i][j] = (G[i][j] + 1) % 3;
                    G[0][0] = (G[0][0] + 1) % 3;
                    G[0][j] = (G[0][j] + 2) % 3;
                    G[i][0] = (G[i][0] + 2) % 3;
                }
            }
        }
        bool could = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (G[i][j] != R[i][j]) could = false;
            }
        }
        cout << (could ? "Yes\n" : "No\n");
    }
    return 0;
}

