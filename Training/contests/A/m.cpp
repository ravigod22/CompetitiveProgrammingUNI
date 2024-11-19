#include <bits/stdc++.h>
using namespace std;
const int mxn = 2e5 + 10;
int n;
vector<int> G[mxn];

vector<int> f(int source) {
    vector<int> dis(n, -1);
    dis[source] = 0;
    queue<int> q;
    q.emplace(source);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : G[u]) {
            if (dis[v] != -1) continue;
            dis[v] = dis[u] + 1;
            q.emplace(v);
        }
    }
    return dis;
}

int main() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    if (n == 1) {
        cout << 0 << "\n";
        return 0;
    }
    vector<int> d;
    for (int i = 0; i < n; ++i) {
        if (G[i].size() == 1) {
            d = f(i);
            break;
        }
    }
    for (int tt = 0; tt < 2; ++tt) {
        int aux = *max_element(d.begin(), d.end());
        vector<int> tmp;
        for (int i = 0; i < n; ++i) {
            if (aux == d[i]) {
                tmp = f(i);
                break;
            }
        }
        for (int i = 0; i < n; ++i) d[i] = max(d[i], tmp[i]);
    }
    for (int i = 0; i < n; ++i) cout << d[i] << " \n"[i + 1 == n];
    return 0;
}
