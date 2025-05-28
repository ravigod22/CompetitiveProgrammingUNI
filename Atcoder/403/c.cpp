#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q; cin >> n >> m >> q;
    set<int> page[n];
    bool all[n];
    fill(all, all + n, false);
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int x, y; cin >> x >> y;
            x--, y--;
            page[x].insert(y);
        }
        else if (op == 2) {
            int x; cin >> x;
            x--;
            all[x] = true;
        }
        else {
            int x, y; cin >> x >> y;
            x--, y--;
            if (all[x] || (page[x].count(y))) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}
