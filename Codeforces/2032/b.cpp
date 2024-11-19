#include <bits/stdc++.h>
using namespace std;


#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n, k; cin >> n >> k;
    if (n == 1) {
        cout << "1\n1\n";
        return;
    }
    if (k == n || k == 1) {
        cout << -1 << "\n";
        return;
    }
    if (k & 1) {
        cout << 3 << "\n";
        cout << 1 << " " << k - 1 << " " << k + 2 << "\n";
    }
    else {
        cout << 3 << "\n";
        cout << 1 << " " << k << " " << k + 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


