#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;
int n, m;
string aux = "narek";
string lett[maxn];
int dp[maxn][5];
bool vis[maxn][5];

void init() {
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 5; ++j) {
            dp[i][j] = -1;
            vis[i][j] = false;
        }
    }
}

int f(int i, int k) {
    if (i == n) return -k;
    if (vis[i][k]) return dp[i][k];
    vis[i][k] = true;
    int& x = dp[i][k] = f(i + 1, k);
    auto& s = lett[i];
    int win = 0;
    for (int j = 0; j < m; ++j) {
        if (s[j] == aux[k]) {
            k++;
            if (k == 5) {
                win += 5;
                k = 0;
            }
        }
        else if (aux.find(s[j]) != -1) win--;
    }
    x = max(x, f(i + 1, k) + win);
    return x;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> lett[i];
    init();
    cout << f(0, 0) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

