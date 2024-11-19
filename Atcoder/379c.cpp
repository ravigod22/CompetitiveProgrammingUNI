#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> p(m);
    for (auto& e : p) cin >> e.first;
    for (auto& e : p) cin >> e.second;
    sort(p.begin(), p.end());
    
    i64 sum = 0, acc = 0;
    for (int i = 0; i < m; ++i) {
        if (sum + 1 < 1LL * p[i].first) {
            cout << -1 << "\n";
            return 0;
        }
        sum += p[i].second;
        acc += 1LL * p[i].first * p[i].second;
    }
    if (sum != n) {
        cout << -1 << "\n";
        return 0;
    }
    cout << (1LL * n * (n + 1)) / 2 - acc << "\n";
    return 0;
}
