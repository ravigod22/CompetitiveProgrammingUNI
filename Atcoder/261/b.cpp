#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

const int maxn = 1e3 + 5;
char g[maxn][maxn];

bool solve() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (g[i][j] == 'W' && g[j][i] != 'L') return true;
            if (g[i][j] == 'L' && g[j][i] != 'W') return true;
            if (g[i][j] == 'D' && g[j][i] != 'D') return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    //cin >> tt;
    while (tt--) {
        cout << (solve() ? "incorrect\n" :"correct\n");
    }
    return 0;
}


