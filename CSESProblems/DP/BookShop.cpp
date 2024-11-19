#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int X = 1e5 + 5;
int h[N], s[N];
int dp[X][N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int cap = 0; cap <= x; ++cap) {
        for (int pos = 0; pos < n; ++pos) {
            dp[cap][pos + 1] = dp[cap][pos];
            if (cap >= h[pos]) dp[cap][pos + 1] = max(dp[cap][pos], dp[cap - h[pos]][pos] + s[pos]);
        }
    }
    cout << dp[x][n] << "\n";
    return 0;
}

