#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n, s; cin >> n >> s;
    int bits = __builtin_popcount(s);
    if (s == 0) {
        if (n & 1) {
            if (n == 1) cout << -1 << "\n";
            else cout << n + 3 << "\n";
        }
        else {
            cout << n << "\n";
        }
        return;
    }
    if (bits >= n) {
        cout << s << "\n";
        return;
    }
    int remain = n - bits;
    if (remain & 1) {
        if (bits > 1) {
            cout << s + remain + 1 << "\n";
        }
        else {
            if (s == 1) {
                cout << s + remain + 3 << "\n";
            }
            else {
                cout << s + remain + 1 << "\n";
            }
        }
    }
    else {
        cout << s + remain << "\n";
    }
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


