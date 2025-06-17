#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
const int mod = 1e9 + 7;    
int f[N], invf[N];

int add(int a, int b) {
    return (a + b) % mod;
}

int mul(int a, int b) {
    return (1LL * a * b) % mod;
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
    if (a < b) return 0;
    if (b < 0) return 0;
    return mul(f[a], mul(invf[b], invf[a - b]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    precomputation();
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << C(a, b) << "\n";
    }
    return 0;
}
