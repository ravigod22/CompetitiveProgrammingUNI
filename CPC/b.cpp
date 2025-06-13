#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

const int mod = 1e9 + 7;
const int N = 2e6 + 1;
int a, b, n;
int f[N], invf[N];

int add(int a, int b) {
    return (a + b) % mod;
}
int mul(int a, int b) {
    return 1LL * a * b % mod;
}

int binpow(int a, int e) {
    int res = 1;
    while (e) {
        if (e & 1) res = mul(res, a);
        a = mul(a, a);
        e /= 2;
    }
    return res;
}

void precomputation() {
    f[0] = f[1] = 1;
    for (int i = 2; i < N; ++i) {
        f[i] = mul(f[i - 1], i);
    }
    invf[N - 1] = binpow(f[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; --i) {
        invf[i] = mul(i + 1, invf[i + 1]);
    }
}

int C(int a, int b) {
    return mul(mul(f[a], invf[b]), invf[a - b]);
}

bool is_ac(int k) {
    while (k) {
        int d = k % 10;
        if (d != a && d != b) return false;
        k /= 10;
    }
    return true;
}


void solve() {
    cin >> a >> b >> n;
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        int as = i, bs = n - i;
        int sum = as * a + b * bs;
        if (is_ac(sum)) {
            ans = add(ans, C(n, i));
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    precomputation();
    int tt = 1; 
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


