#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int maxn = 3e6 + 5;
int f[maxn], invf[maxn];

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

int inv(int a) {
    return binpow(a, mod - 2);
}

void precomputation() {
    f[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        f[i] = mul(f[i - 1], i);
    }
    invf[maxn - 1] = inv(f[maxn - 1]);
    for (int i = maxn - 2; i >= 0; --i) {
        invf[i] = mul(invf[i + 1], i + 1);
    }
}

int C(int a, int b) {
    if (a < b) return 0;
    return mul(mul(f[a], invf[b]), invf[a - b]);
}


int main() {
    precomputation();
    int a, o, b, g;
    cin >> a >> o >> b >> g;
    //a -> apple, b -> oranges, c -> bananas, d -> 
    // first case 
    int res = 0;
    for (int i = 0; i < b; ++i) {
        int bars = i + a + 1;
        int remain = b - i - 1;
        res = add(res, mul(C(o + bars, o), C(g - 1 + remain, remain)));
    }
    res = add(res, mul(C(g - 1 + b, b), C(a + o, o)));
    cout << res << "\n";
    return 0;
}
