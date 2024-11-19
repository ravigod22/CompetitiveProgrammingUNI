#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    long long b, c, d; cin >> b >> c >> d;
    long long ans = 0;
    bool can = true;
    for (long long i = 61; i >= 0 && can; --i) {
        long long bitb = (b >> i) & 1LL; 
        long long bitc = (c >> i) & 1LL;
        long long bitd = (d >> i) & 1LL;
        if (bitb) {
            if (bitd == 0) {
                if (bitc == 0) can = false;
                else ans |= (1LL << i);
            }
        }
        else {
            if (bitd) {
                if (bitc) can = false;
                else ans |= (1LL << i);
            }
        }
    }
    if (can) {
        assert((ans | b) == d + (ans & c));
        assert(ans <= (1LL << 61));
        cout << ans << "\n";
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


