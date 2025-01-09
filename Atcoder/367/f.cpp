#include <bits/stdc++.h>
using namespace std;

const int B = 4e5;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<int> a(n), b(n);
    for (int& e : a) cin >> e;
    for (int& e : b) cin >> e;
    vector<int> preA(n + 1, 1), preB(n + 1, 1);
    for (int i = 0; i < n; ++i) {
        preA[i + 1] = mul(preA[i], add(B, a[i]));
        preB[i + 1] = mul(preB[i], add(B, b[i]));
    }
    for (int i = 0; i < q; ++i) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int ans1 = mul(preA[r1], inverse(preA[l1 - 1]));
        int ans2 = mul(preB[r2], inverse(preB[l2 - 1]));
        cout << (ans1 == ans2 ? "Yes" : "No") << "\n";
    }
    return 0;
}
