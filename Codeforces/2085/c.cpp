#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        i64 x, y; cin >> x >> y;
        if (x < y) swap(x, y);
        if (x == y) {
            cout << -1 << "\n";
            continue;
        }
        int last = -1;
        for (int i = 63; i >= 0; --i) {
            int bit1 = (x >> i) & 1;
            int bit2 = (y >> i) & 1;
            if (bit1) {
                last = i - 1;
                break;
            }
        }
        i64 k = 0;
        for (int j = last; j >= 0; --j) {
            if ((x >> j) & 1) continue;
            k |= (1LL << j);
        }
        k++;
        if ((x + k) & (y + k)) cout << -1 << "\n";
        else cout << k << "\n";
    }   
    return 0;
}


