#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

const int mod = 1e9 + 7; 

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

int inverse(int x) {
    return binpow(x, mod - 2);
}

int sum(i64 l) {
    int L = int(l % mod);
    int res = 1;
    res = mul(res, L);
    res = mul(res, L + 1);
    res = mul(res, inverse(2));
    return res;
}

int rangeSum(i64 l, i64 r) {
    int L = sum(l - 1);
    int R = sum(r);
    return (R - L + mod) % mod;
}

int sumsquare(int l) {
    int res = 1;
    res = mul(res, l);
    res = mul(res, l + 1);
    res = mul(res, 2 * l + 1);
    res = mul(res, inverse(6));
    return res;
}

int rangeSquare(int l, int r) {
    // [L, R]
    int L = sumsquare(l - 1);
    int R = sumsquare(r);
    return (R - L + mod) % mod;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        i64 k; cin >> k;
        if (n <= 2) {
            if (n == 1) cout << (k - 1) % mod << "\n";
            else cout << (2LL * (k - 1) - 1) % mod << "\n";
            continue;
        }
        // [2, sqrt(n)] - [sqrt(n) + 1, n], [n + 1, k]
        int f1 = sqrt(n);
        dbg(f1);
        int ans = 0;
        if (2LL <= k) {
            for (int i = 2; i <= min(k, 1LL * f1); ++i) {
                int tmp = n;
                int aux = 0;
                while (tmp) {
                    int div = tmp / i;
                    int remain = tmp % i;
                    aux = mul(aux, i);
                    aux = add(aux, remain);
                    tmp = div;
                }
            }
        }
        if (0LL + f1 + 1 <= k) {
            int s = f1 + 1;
            int lim = int(min(1LL * n, k));
            int aux = lim;
            dbg(lim);
            int x = 0;
            for (int i = n / lim + 1; i <= f1 + 1; ++i) {
                // ]L : R]
                raya;
                dbg(i);
                int R = aux;
                int L = (n / i);
                int d = R - L;
                dbg(L);
                dbg(R);
                dbg(d);
                ans = add(ans, mul(d, i - 1));
                int tmp = (mul(n, rangeSum(L + 1, R)) - mul(mul(d, i - 1), rangeSquare(L + 1, R)) + mod) % mod;
                ans = add(ans, tmp);
                aux = L;
            }
        }
        if (0LL + n + 1 <= k) {
            ans = add(ans, (k - n) % mod * n % mod);
        }
        cout << ans << "\n";
    }
    return 0;
}
