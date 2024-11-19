#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, q; cin >> n >> m >> q;
    set<int> pos;
    for (int i = 0; i < m; ++i) {
        int x; cin >> x;
        pos.emplace(x);
    }
    for (int i = 0; i < q; ++i) {
        int d; cin >> d;
        pos.emplace(d);
        auto it = pos.find(d);
        if (it == pos.begin()) {
            auto itnext = next(it);
            cout << *itnext - 1;
        }
        else if (next(it) == pos.end()) {
            auto previt = prev(it);
            cout << n - *previt;
        }
        else {
            auto previt = prev(it);
            auto nextit = next(it);
            int tmp = (*previt + *nextit) / 2;
            cout << tmp - *previt;
        }
        cout << "\n";
        pos.erase(d);
    }
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

