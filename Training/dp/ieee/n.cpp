#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
string x, y;
int dp[N][N];

void init() {
    for (int i = 0; i <= x.size(); ++i) {
        for (int j = 0; j <= y.size(); ++j) {
            dp[i][j] = -1;
        }
    }
}
int f(int i, int j) {
    if (i == x.size()) return 0;
    if (j == y.size()) return 0;
    int& memo = dp[i][j];
    if (~memo) return memo;
    memo = max(f(i + 1, j), f(i, j + 1));
    if (x[i] == y[j]) {
        memo = max(memo, 1 + f(i + 1, j + 1));
    }
    return memo;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        cin >> x >> y;
        init();
        cout << f(0, 0) << "\n";
    }
    return 0;
}
