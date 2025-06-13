#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl
const i64 inf = 1e18;

void solve() {
    int n;
    cin >> n;
    int G[n][n];
    vector<int> del(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> G[i][j];
    for (int& e : del) {
        cin >> e;
        e--;
    }
    reverse(del.begin(), del.end());
    i64 dis[n][n];
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dis[i][j] = inf;
    vector<i64> ans(n);
    for (int k = 0; k < n; ++k) {
        // update 
        int pivote = del[k];
        for (int i = 0; i < n; ++i) {
            dis[pivote][i] = min(dis[pivote][i], 1LL * G[pivote][i]);
            dis[i][pivote] = min(dis[i][pivote], 1LL * G[i][pivote]);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int u = del[i], v = del[j];
                if (dis[u][pivote] < inf && dis[pivote][v] < inf) {
                    dis[u][v] = min(dis[u][v], dis[u][pivote] + dis[pivote][v]);
                }
            }
        }
        i64 acc = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dis[i][j] < inf) acc += dis[i][j];
            }
        }
        ans[k] = acc;
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}



