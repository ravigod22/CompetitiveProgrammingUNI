#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int r; cin >> r;
    // x ^ 2 + y ^ 2 <= r ^ 2;
    int cnt = 0;
    for (int x = -1000; x <= 1000; x++) {
        for (int y = -1000; y <= 1000; ++y) {
            if (x * x + y * y <= r * r) cnt++;
        }
    }
    cout << r << " " << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


