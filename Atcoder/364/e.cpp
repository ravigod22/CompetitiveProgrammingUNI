#include <bits/stdc++.h>
using namespace std;
const int mxn = 85;
const int INF = 1e9 + 5;
int n, x, y;
int a[mxn];
int b[mxn];
int dp[mxn][mxn * 10001];
int dp1[mxn][mxn * 10001];
int choose[mxn]; 
int choose1[mxn];

int f(int i, int w) {
    if (w < 0) return -INF;
    if (i == n) return 0;
    if (~dp[i][w]) return dp[i][w];
    int& x = dp[i][w];
    x = max(f(i + 1, w), f(i + 1, w - b[i]) + a[i]);
    return x;
}
int f1(int i, int w) {
    if (w < 0) return -INF;
    if (i == n) return 0;
    if (~dp1[i][w]) return dp1[i][w];
    int& x = dp1[i][w];
    x = max(f1(i + 1, w), f1(i + 1, w - a[i]) + b[i]);
    return x;
}

void build(int i, int w) {
    if (w < 0) return;
    if (i == n) return;
    if (f(i + 1, w) < f(i + 1, w - b[i]) + a[i]) {
        choose[i] = 1;
        build(i + 1, w - b[i]);
    }
    else {
        choose[i] = 0;
        build(i + 1, w);
    }
}
void build1(int i, int w) {
    if (w < 0) return;
    if (i == n) return;
    if (f1(i + 1, w) < f1(i + 1, w - a[i]) + b[i]) {
        choose1[i] = 1;
        build1(i + 1, w - a[i]);
    }
    else {
        choose1[i] = 0;
        build1(i + 1, w);
    }
}
int main() {
    cin >> n >> x >> y;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    int ans = 0;
    for (int i = 0; i <= x; ++i) {
        if (f(0, i) <= y) {
            build(0, i);
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                //cout << choose[j] << " \n"[j + 1 == n];
                cnt += choose[j];
            }
            ans = max(ans, cnt);
        }
    }
    for (int j = 0; j <= y; ++j) {
        if (f1(0, j) <= x) {
            build1(0, j);
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                //cout << choose[i] << " \n"[i + 1 == n];
                cnt += choose1[i];
            }
            ans = max(ans, cnt);
        }
    }
    cout << max(ans, 1) << "\n";
    return 0;
}
