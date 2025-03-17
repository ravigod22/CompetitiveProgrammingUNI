#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int x; cin >> x;
    int bit = 31 - __builtin_clz(x);
    int y = (1 << bit) - 1;
    int z = x ^ y;
    if (abs(y - z) < x && x < y + z) {
        cout << y << "\n";
    }
    else cout << -1 << "\n";
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

