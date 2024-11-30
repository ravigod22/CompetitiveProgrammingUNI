#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n; cin >> n;
    char grid[n + 1][2];
    bool up = 1;
    int posx = 0, posy = 0;
    for (int e : {0, 1}) {
        for (int i = 1; i <= n; ++i) {
            cin >> grid[i][e];
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (up) {
            if (grid[i][0] != '1' && grid[i][0] != '2') {
                if (grid[i][1] == '1' or grid[i][1] == '2') return 0;
                posx = 1;
                up ^= 1;
            }
        }
        else {
            if (grid[i][1] != '1' && grid[i][1] != '2') {
                if (i == n) return 0;
                if (grid[i][0] == '1' or grid[i][0] == '2') return 0;
                posx = 0;
                up ^= 1;
            }
        }
        posy++;
        if (posx == 1 && posy == n) return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        cout << (solve() ? "YES" : "NO") << "\n";        
    }
    return 0;
}
