#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

bool solve() {
    int n, m, q; cin >> n >> m >> q;
    vector<int> a(n), b(m);
    for (auto &e : a) cin >> e;
    for (auto &e : b) cin >> e;
    set<int> possible;
    int p = 0;
    for (int i = 0; i < m; ++i) {
        if (possible.count(b[i])) {
            continue;
        }
        if (b[i] == a[p] && p < n) {
            possible.emplace(a[p]);
            p++;
        }
        else return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        cout << (solve() ? "YA" : "TIDAK") << "\n";
    }
    return 0;
}

