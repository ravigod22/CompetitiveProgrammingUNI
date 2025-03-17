#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

void solve() {
    int n, x; cin >> n >> x;
    int oracc = 0;
    int a[3][n];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((a[i][j] & x) == a[i][j]) {
                oracc |= a[i][j];
            }
            else break;
        }
    }
    cout << ((oracc & x) == x ? "YES" : "NO") << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

