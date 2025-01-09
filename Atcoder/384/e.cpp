#include <bits/stdc++.h>
using namespace std;
using u128 = __int128;
using i64 = long long;
using pii = pair<int, int>;

const int maxn = 5e2 + 5;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int h, w, X;
i64 s[maxn][maxn];
bool vis[maxn][maxn];

int main() {
    cin >> h >> w >> X;
    int p, q; cin >> p >> q;
    p--; q--;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> s[i][j];
        }
    }
    i64 sum = s[p][q];
    vis[p][q] = 1;
    priority_queue<pair<i64, pii>, vector<pair<i64, pii>>, greater<pair<i64, pii>>> Q;
    for (int i = 0; i < 4; ++i) {
        int ii = dx[i] + p;
        int jj = dy[i] + q;
        if (ii < 0 || jj < 0 || ii >= h || jj >= w) continue;
        Q.emplace(s[ii][jj], make_pair(ii, jj));
        vis[ii][jj] = 1;
    }
    while (!Q.empty()) {
        auto [e, cor] = Q.top();
        auto [x, y] = cor;
        Q.pop();
        if ((u128)e * X >= (u128)sum) continue;
        sum += e;
        for (int k = 0; k < 4; ++k) {
            int ii = dx[k] + x;
            int jj = dy[k] + y;
            if (ii < 0 || jj < 0 || ii >= h || jj >= w) continue;
            if (vis[ii][jj]) continue;
            Q.emplace(s[ii][jj], make_pair(ii, jj));
            vis[ii][jj] = 1;
        }
    }
    cout << sum << "\n";
    return 0;
}
