#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m;
vector<int> G[N];
int color[N];
int flags[N];
bool ans;
// 0 : white, 1 : gray, 2 : black
void DFS_visit(int u, int p) {
    color[u] = 1;
    flags[u] = p;
    for (int v : G[u]) {
        if (color[v] == 2) continue;
        if (color[v] == 0) {
            flags[v] = 3 - p;
            DFS_visit(v, 3 - p); 
        }
        else {
            if (flags[v] == p) {
                ans = false;
                return;
            }
        }
    }
    color[u] = 2;
}
void DFS() {
    ans = true;
    for (int i = 0; i < n; ++i) {
        if (color[i]) continue;
        DFS_visit(i, 1);
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    DFS();
    if (ans) {
        for (int i = 0; i < n; ++i) {
            cout << flags[i] << " \n"[i + 1 == n]; 
        }
    } 
    else cout << "IMPOSSIBLE";
}  
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
