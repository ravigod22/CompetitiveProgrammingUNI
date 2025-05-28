#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int maxn = 15;
const int maxm = 110;
const int inf = 1e9;
int n, m;
vector<int> G[maxn];
i64 res;
int c[maxn];

void back(int pos, vector<int> &cnt, i64 add) {
    if (pos == n) {
        bool can = true;
        for (int e : cnt) {
            if (e < 2) can = false;
        }
        if (can) res = min(res, add);
        return;
    }
    back(pos + 1, cnt, add);
    for (int i = 1; i <= 2; ++i) {
        for (int e : G[pos]) {
            cnt[e] += i;
        }
        add += 1LL * i * c[pos];
        back(pos + 1, cnt, add);
        for (int e : G[pos]) {
            cnt[e] -= i;
        }
        add -= 1LL * i * c[pos];
    }
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> c[i];
    for (int i = 0; i < m; ++i) {
        int len; cin >> len;
        for (int j = 0; j < len; ++j) {
            int zoo; cin >> zoo;
            zoo--;
            G[zoo].push_back(i);
        }       
    }
    res = 1e18;
    vector<int> cnt(m, 0);
    back(0, cnt, 0);
    cout << res << "\n";
    return 0;
}
