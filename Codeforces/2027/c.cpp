#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<i64> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        map<i64, vector<i64>> mp;
        for (int i = 1; i < n; ++i) {
            mp[a[i] + i].emplace_back(a[i] + 2 * i);
        }
        set<i64> aux;
        auto dfs = [&] (auto& self, i64 u) -> void {
            if (aux.count(u)) return;
            aux.insert(u);
            for (auto v : mp[u]) {
                self(self, v);
            }
        };
        dfs(dfs, 1LL * n);
        cout << *aux.rbegin() << "\n";
    }
    return 0;
}
