#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int a[2][2];
    int ans = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> a[i][j];
            if (j == 0) ans += a[i][j];
            else ans -= a[i][j];
        }
    }
    if (ans > 0) cout << "A\n";
    else if (ans == 0) cout << "D\n";
    else cout << "P\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    while (tt--) {
        solve();
    }
    return 0;
}



