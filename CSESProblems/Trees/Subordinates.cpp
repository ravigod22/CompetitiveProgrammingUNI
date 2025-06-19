#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
int cnt[N];
vector<int> G[N];

void dfs(int u) {
    cnt[u] = 1;
    for (int v : G[u]) {
        dfs(v);
        cnt[u] += cnt[v];
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int p; cin >> p;
        --p;
        G[p].emplace_back(i);
    }
    dfs(0);
    for (int i = 0; i < n; ++i) {
        cout << cnt[i] - 1 << " \n"[i + 1 == n];
    }
    return 0;
}
