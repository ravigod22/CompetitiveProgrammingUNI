#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    i64 n; cin >> n;
    int k; cin >> k;
    vector<i64> primes(k);
    for (auto& e : primes) cin >> e;
    vector<i64> cnt(k + 1);
    for (int i = 1; i < (1 << k); ++i) {
        i64 tmp = n;
        int pos = __builtin_popcount(i);
        for (int j = 0; j < k; ++j) {
            if ((i >> j) & 1) {
                tmp /= primes[j];
            }    
        }
        cnt[pos] += tmp;
    }
    i64 sum = 0;
    for (int i = 1; i <= k; ++i) {
        if (i & 1) sum += cnt[i];
        else sum -= cnt[i];
    }
    cout << sum << "\n";
    return 0;
}
