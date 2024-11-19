#include <bits/stdc++.h>
using namespace std;
const int maxn = 410;
const int maxm = 1e6 + 10;
int d[maxn][maxn];
int sq[maxm];
int square(int x) {
     return x * x;
}

void init() {
    for (int i = 0; i * i <= 1e6; ++i) {
        sq[i * i] = i;
    }
}

int main() {
    init();
    int n, m; cin >> n >> m;
    memset(d, -1, sizeof(d));
    d[1][1] = 0;
    queue<pair<int, int>> q;
    q.emplace(1, 1);
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (int i = 1; i <= n; ++i) {
            int tmp = square(u.first - i);
            int need = m - tmp;
            if (need < 0) continue;
            int r = sq[need];
            if (square(r) != need) continue;
            int l1 = u.second + r;
            int l2 = u.second - r;
            if ((0 < l1 && l1 <= n) && d[i][l1] == -1) {
                d[i][l1] = 1 + d[u.first][u.second];
                q.emplace(i, l1);
            }
            if ((0 < l2 && l2 <= n) && d[i][l2] == -1) {
                d[i][l2] = 1 + d[u.first][u.second];
                q.emplace(i, l2);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << d[i][j] << " \n"[j == n];
        }
    }
    return 0;
}

