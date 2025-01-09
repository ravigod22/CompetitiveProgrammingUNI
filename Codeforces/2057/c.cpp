#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int l, r; cin >> l >> r;
    int remain = 0;
    for (int i = 29; i >= 0; --i) {
        int bit1 = (r >> i) & 1;
        int bit2 = (l >> i) & 1;
        remain |= (bit1 << i);
        if (bit1 > bit2) {
            break;
        }
    }
    int a = remain;
    int b = remain - 1;
    if (a + 1 <= r) {
        cout << a << " " << b << " " << a + 1 << "\n";
    }
    else cout << a << " " << b << " " << b - 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


