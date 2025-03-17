#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n, k; cin >> n >> k;
    int lastodd = (k & 1 ? k : k - 1);
    int lasteven = (k & 1 ? k - 1 : k);
    int ans = 0;
    if (n & 1) {
        n -= lastodd;
        ans++;
    }
    ans += (n + lasteven - 1) / lasteven;
    cout << ans << "\n";
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


