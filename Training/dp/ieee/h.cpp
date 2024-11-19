#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const int maxw = 1e4 + 10;
const int inf = 1e9;
int N, W;
int w[maxn], v[maxn];
int dp[maxn][maxw];

int f(int pos, int weight) {
    if (weight < 0) return -inf;
    if (pos == N) return 0;
    int& x = dp[pos][weight];
    if (~x) return x;
    x = f(pos + 1, weight);
    x = max(x, v[pos] + f(pos + 1, weight - w[pos]));
    x = max(x, v[pos] + f(pos, weight - w[pos]));
    return x;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> N >> W;
    for (int i = 0; i < N; ++i) cin >> v[i] >> w[i];
    cout << f(0, W) << "\n";
    return 0;
}
