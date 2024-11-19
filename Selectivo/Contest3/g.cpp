#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl
const int mod = 998244353;

int add(int a, int b) {
    return (a + b) % mod;
}

int mul(int a, int b) {
    return 1LL * a * b % mod;
}

int binpow(int a, int e) {
    int result = 1;
    while (e) { 
        if (e & 1) result = mul(result, a);
        a = mul(a, a);
        e /= 2;
    }
    return result;
}

void solve() {
    int n; cin >> n;
    cout << binpow(n, mod - 2) << "\n";
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



