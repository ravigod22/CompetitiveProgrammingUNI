#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    if (n % 2 == 0) {
        cout << -1 << "\n";
        return;
    }
    cout << n << " ";
    for (int i = 1; i <= n - 1; ++i) cout << i << " \n"[i == n - 1];
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


