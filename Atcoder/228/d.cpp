#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int maxn = 1 << 20;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<i64> a(maxn, -1);
    set<i64> tmp;
    for (int i = 0; i < maxn; ++i) tmp.emplace(i);
    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        i64 x; cin >> x;    
        i64 aux = x % maxn;
        if (t == 1) {
            auto it = tmp.lower_bound(aux);
            if (it != tmp.end()) {
                a[*it] = x;
                tmp.erase(it);
            }
            else {
                a[*tmp.begin()] = x;
                tmp.erase(tmp.begin());
            }
        }
        else {
            int pos = aux;
            cout << a[pos] << "\n";
        }
    }
    return 0;
}
