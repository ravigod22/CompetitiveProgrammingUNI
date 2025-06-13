#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 5e5 + 5;

int n;
int a[N];
ll sum[N];
vector<int> G[N];

ll dfs(int u) {
    ll ans = 0;
    sum[u] = a[u];
    vector<ll> best;
    for (int v : G[u]) {
        best.push_back(dfs(v));
        sum[u] += sum[v];
    }
    ans = max(ans, sum[u]);
    sort(best.begin(), best.end());
    ll pans = 0;
    while(!best.empty() and best.back() > 0) {
        pans += best.back();
        best.pop_back();
    }
    ans = max(ans, pans);
    return ans;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int p; cin >> p;
        p--;
        G[p].push_back(i);
    }
    cout << dfs(0) << "\n";

    return 0;
}
