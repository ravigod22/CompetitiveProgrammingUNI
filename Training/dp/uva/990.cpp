#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int maxn = 32;
const int maxt = 1e3 + 10;
const int inf = 1e9;
int N, T, W;
int d[maxn], v[maxn];
int dp[maxn][maxt];
vector<int> ind;

int get(int pos) {
    return 3 * W * d[pos];
} 

void init() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= T; ++j) {
            dp[i][j] = -1;
        }
    }
}

int f(int pos, int remain) {
    if (remain < 0) return -inf;
    if (pos == N) return 0;
    int& x = dp[pos][remain];
    if (~x) return x;
    x = max(f(pos + 1, remain), v[pos] + f(pos + 1, remain - get(pos)));
    return x;
}

void build(int pos, int remain) {
    if (remain < 0) return;
    if (pos == N) return;
    if (f(pos + 1, remain) <= v[pos] + f(pos + 1, remain - get(pos))) {
        ind.emplace_back(pos);
        build(pos + 1, remain - get(pos));
    }
    else build(pos + 1, remain);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    bool more = false;
    while (cin >> T >> W) {
        if (more) cout << "\n";
        memset(dp, -1, sizeof(dp));
        cin >> N;
        for (int i = 0; i < N; ++i) cin >> d[i] >> v[i];
        build(0, T);
        cout << f(0, T) << "\n";
        cout << ind.size() << "\n";
        for (int i = 0; i < ind.size(); ++i) {
            int e = ind[i];
            cout << d[e] << " " << v[e] << "\n";
        }
        ind.clear();
        more = true;
    }
    return 0;
}
