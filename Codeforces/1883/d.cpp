#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q; cin >> q;
    multiset<int> l, r;
    while (q--) {
        char op; cin >> op;
        int x, y; cin >> x >> y;
        if (op == '+') {
            l.emplace(x);
            r.emplace(y);
        }
        else {
            l.extract(x);
            r.extract(y);
        }
        if (!l.empty() && *l.rbegin() > *r.begin()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}


