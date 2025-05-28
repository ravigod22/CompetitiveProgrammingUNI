#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int adj[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adj[i][j];
        }
    }
    int ans = 0;
    set<tuple<int, int, int>> s;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (k == i || k == j || i == j) continue;
                if (adj[i][j] > adj[i][k] + adj[k][i]) {
                    cout << -1 << "\n";
                    return 0;
                }
            }
        }
    }
    if (n <= 2) {
        cout << 0 << "\n";
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int cnt = 0;
            for (int k = 0; k < n; ++k) {
                if (k == i || k == j) continue;
                if (adj[i][j] == adj[i][k] + adj[k][j]) cnt++;
            }
            if (cnt == n - 2) ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
