#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        set<long long> tmp;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            tmp.emplace(x);
        }
        for (int i = 0; i < m; ++i) {
            char op; cin >> op;
            int l, r; cin >> l >> r;
            auto it = tmp.upper_bound(r);
            if (it != tmp.begin()) {
                --it;
                if (*it >= l) {
                    int aux = *it;
                    if (op == '+') {
                        tmp.erase(it);
                        tmp.emplace(aux + 1);
                    }
                    else {
                        tmp.erase(it);
                        tmp.emplace(aux - 1);
                    }
                }
            }
            cout << *tmp.rbegin() << " \n"[i + 1 == m];
        }
    }
    return 0;
}
