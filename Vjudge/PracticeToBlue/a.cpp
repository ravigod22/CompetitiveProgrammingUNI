#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> w(n);
        for (int& e : w) cin >> e;
        vector<pair<int, int>> edge;
        for (int i = 1; i < n; ++i) {
            int u, v; cin >> u >> v;
            u--; v--;
            edge.emplace_back(u, v);
        }

    }
    return 0;
}
