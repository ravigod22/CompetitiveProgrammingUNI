#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;

int n;
string s;
vector<int> G[maxn];
vector<int> ans;
bool vis[maxn];

void DFS(int u) {
    vis[u] = true;
    ans.emplace_back(u);
    for (int v : G[u]) {
        if (vis[v]) continue;
        DFS(v);
    }
}

void solve() {
    cin >> n;
    fill(G, G + n, vector<int>());
    fill(vis, vis + n, false);
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
        G[i].emplace_back(p[i]);
        G[p[i]].emplace_back(i);
    }
    cin >> s;
    vector<int> result(n);
    for (int j = 0; j < n; ++j) {
        if (vis[j]) continue;
        ans.clear();
        DFS(j);
        vector<int> tmp;
        int a = ans.size();
        vector<int> prefix(2 * a + 1, 0); 
        for (int i = 0; i < ans.size(); ++i) {
            tmp.emplace_back((s[ans[i]] == '0' ? 1 : 0));
        }
        for (int i = 0; i < ans.size(); ++i) {
            tmp.emplace_back((s[ans[i]] == '0' ? 1 : 0));
        }
        for (int i = 0; i < tmp.size(); ++i) {
            prefix[i + 1] = prefix[i] + tmp[i];
        }
        for (int i = 0; i < ans.size(); ++i) {
            int aux = prefix[i + a + 1] - prefix[i + 1];
            result[ans[i]] = aux;
        }
    }
    for (int i = 0; i < n; ++i) cout << result[i] << " \n"[i + 1 == n];
    ans.clear();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}



