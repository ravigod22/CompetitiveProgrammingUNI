#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int color[maxn];
bool vis[maxn];
vector<int> G[maxn];
bool ans;
int cnt;
void ask(int u, bool change) {
    if (cnt++) cout << "M " << u << endl;
    int k; cin >> k;
    for (int i = 0; i < k; ++i) {
        int x; cin >> x;
        if (change) G[u].emplace_back(x);
    }
}


void DFS(int u, int p = -1) {
    ask(u, 1);
    vis[u] = true;
    for (int v : G[u]) {
        if (vis[v]) {
            if (color[u] == color[v]) {
                ans = 0;
            }
        }
        else {
            color[v] = 1 ^ color[u];
            DFS(v, u);
        }
    }
    if (p != -1) ask(p, 0);
}

int main() {
    ans = true;
    cnt = 0;
    DFS(1);
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
