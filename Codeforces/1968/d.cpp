#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

const int maxn = 2e5 + 5;
vector<int> G[maxn];

void solve() {
    int n, k, b, s; cin >> n >> k >> b >> s;
    b--, s--;
    vector<int> perm(n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> perm[i];
        perm[i]--;
        G[i].push_back(perm[i]);
    }
    for (int& e : a) cin >> e;
    vector<int> tmp, ans;
    vector<i64> prefix(n, 0LL);
    vector<bool> vis(n, 0);
    auto dfs = [&] (auto& self, int u) -> void {
        vis[u] = true;
        tmp.push_back(u);
        ans.push_back(a[u]);
        for (int v : G[u]) {
            if (vis[v]) continue;
            self(self, v);
        }
    };
    dfs(dfs, b);
    for (int i = 0; i < (int)ans.size(); ++i) {
        prefix[i] = (i ? prefix[i - 1] : 0) + ans[i];
    }
    i64 Bodya = 0;
    for (int i = 0; i < (int)ans.size() && i < k; ++i) {
        i64 sum = prefix[i] + 1LL * ans[i] * max(0, k - i - 1);
        Bodya = max(Bodya, sum);
    }
    vis.assign(n, 0);
    prefix.assign(n, 0LL);
    tmp.clear();
    ans.clear();
    dfs(dfs, s);
    for (int i = 0; i < (int)ans.size(); ++i) {
        prefix[i] = (i ? prefix[i - 1] : 0) + ans[i];
    }
    i64 Sasha = 0;
    for (int i = 0; i < (int)ans.size() && i < k; ++i) {
        i64 sum = prefix[i] + 1LL * ans[i] * max(0, k - i - 1);
        Sasha = max(Sasha, sum);
    }
    if (Bodya == Sasha) cout << "Draw\n";
    else if (Bodya > Sasha) cout << "Bodya\n";
    else cout << "Sasha\n";
    for (int i = 0; i < n; ++i) G[i].clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

