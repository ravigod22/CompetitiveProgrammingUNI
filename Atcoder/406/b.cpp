#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mul(i64 a, i64 b, i64 mod) {
    if ((__uint128_t)a * b >= (__uint128_t)mod) return 1;
    else return a * b;
}


int main() {
    int n, k;
    cin >> n >> k;
    vector<i64> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    i64 display = 1;
    i64 mod = 1;
    for (int i = 0; i < k; ++i) {
        mod *= 10;
    }
    for (int i = 0; i < n; ++i) {
        display = mul(display, a[i], mod);
    }
    cout << display << "\n";
    return 0;
}

