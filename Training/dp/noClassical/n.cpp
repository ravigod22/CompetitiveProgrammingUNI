#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 110;
int n, m, k, area;
int p[N][N];
i64 pre[N][N];
i64 cost;

i64 sum(int a, int b, int c, int d) {
    return pre[a][b] - pre[a][d] - pre[c][b] + pre[c][d];
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> p[i][j];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            pre[i][j] = 1LL * p[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j <= m; ++j) {
            int b = 0;
            for (int a = 1; a <= n; ++a) {
                while (b < a && sum(a, j, b, i) > 1LL * k) b++;
                int tmp = (j - i) * (a - b);
                if (area <= tmp) {
                    if (area == tmp) {
                        if (cost > sum(a, j, b, i)) {
                            cost = sum(a, j, b, i);
                        }
                    }
                    else {
                        area = tmp;
                        cost = sum(a, j, b, i);
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; ++i) {
        area = 0;
        cost = 0;
        solve();
        cout << "Case #" << i << ": " << area << " " << cost << "\n";
    }
    return 0;
}
