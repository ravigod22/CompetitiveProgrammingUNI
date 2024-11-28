#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e3 + 10;
vector<int> G[maxn];
int par[maxn];
int siz[maxn];

int get(int a) {
    return (a == par[a]) ? a : par[a] = get(par[a]);
}

bool can(int a, int b) {
    a = get(a), b = get(b);
    return a != b;
}

bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b) return 0;
    if (siz[a] < siz[b]) swap(a, b);
    par[b] = a;
    siz[a] += siz[b];
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        int n, m1, m2; cin >> n >> m1 >> m2;
        for (int i = 0; i < 2 * n; ++i) par[i] = i, siz[i] = 1;
        for (int i = 0; i < m1; ++i) {
            int u, v; cin >> u >> v;
            u--, v--;
            join(u, v);
        }
        for (int i = 0; i < m2; ++i) {
            int u, v; cin >> u >> v;
            u--, v--;
            join(u + n, v + n);
        }
        vector<pair<int, int>> ans;
        for (int i = 0; i + 1 < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (can(i, j) && can(i + n, j + n)) {
                    ans.emplace_back(i + 1, j + 1);
                    join(i, j), join(i + n, j + n);
                }                
            }
        }
        cout << ans.size() << "\n";
        for (auto e : ans) cout << e.first << " " << e.second << "\n";
    }
    return 0;
}
