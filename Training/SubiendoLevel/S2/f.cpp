#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


int main() {
    i64 l, r; cin >> l >> r;
    if (l == r) cout << 0 << "\n";
    else {
        i64 aux= l ^ r;
        int bit = 63 - __builtin_clzll(aux);
        cout << (1LL << (bit + 1)) - 1 << "\n";
    }
    return 0;
}
