#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int binpow(int a, int b) {
    int result = 1;
    while (b) {
        if (b & 1) result = 1LL * result * a % mod;
        a = 1LL * a * a % mod;
        b = b / 2;
    }
    return result;
}


int main() {
    int n, m, k; cin >> n >> m >> k;
    if (k > 1 && k < n) cout << (k & 1 ? m * m : m);
    else if (k == n) cout << binpow(m, (n + 1) / 2);
    else cout << binpow(m, n); 
    return 0;
}
