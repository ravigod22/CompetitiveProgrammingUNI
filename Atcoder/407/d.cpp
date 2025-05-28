#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int h, w;
i64 table[20][20];
i64 dp[1 << 20];

i64 g(int mask) {
    i64 res = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int pos = i * h + j;
            if ((mask >> pos) & 1) res ^= table[i][j];
        }
    }
    return res;
}

i64 f(int mask) {
    // if (is_full(mask)) return 0;
    if (~dp[mask]) return dp[mask];
    i64& res = dp[mask] = g(mask);
    // i64 tmp = g(mask);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int pos = i * h + j;
            if (!((mask >> pos) & 1)) continue;
            int lastx = (i + 1) * h + j;
            int lasty = i * h + j + 1;
            if (i + 1 < h && ((mask >> lastx) & 1)) {
                res = max(res, f((mask ^ (1 << pos) ^ (1 << lastx))));
            }
            if (j + 1 < w && ((mask >> lasty) & 1)) {
                res = max(res, f((mask ^ (1 << pos) ^ (1 << lasty))));
            }
        }
    }
    return res;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> h >> w;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            cin >> table[i][j];
    int len = h * w;
    cout << f((1 << len) - 1) << "\n";
    return 0;
}
