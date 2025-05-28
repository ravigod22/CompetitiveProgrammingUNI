#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q; cin >> q;
    multiset<i64> aux;
    i64 carry = 0;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            i64 x; cin >> x;
            aux.insert(x - carry);
        }
        else if (op == 2) {
            i64 x; cin >> x;
            carry += x;
        }
        else {
            cout << (*aux.begin() + carry) << "\n";
            aux.extract(*aux.begin());
        }
    }
    return 0;
}
