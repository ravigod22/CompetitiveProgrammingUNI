#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxn = 2e6 + 1;
int lp[maxn];
vector<int> pr;

i64 binpow(i64 a, i64 e) {
    i64 res = 1;
    while (e) {
        if (e & 1) res = res * 1LL * a;
        a = 1LL * a * a;
        e /= 2;
    }
    return res;
}

void sieve() {
    for (int i = 2; i < maxn; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.emplace_back(i);
        }
        for (int j = 0; i * pr[j] < maxn; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) break;
        }
    }
}

int main() {
    sieve();
    i64 n; cin >> n;
    i64 cnt = 0;
    for (int i = 0; i <= 12; ++i) {
        if (binpow(pr[i], 8) <= n) cnt++;
    }
    for (int i = 0; i < (int)pr.size(); ++i) {
        int e = pr[i];
        int lo = 0;
        int hi = (int)pr.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (1LL * pr[mid] * e >= 1e9) {
                hi = mid - 1;
                continue;
            }
            if (1LL * pr[mid] * e * e * pr[mid] <= n) lo = mid;
            else hi = mid - 1;
        }
        if (1LL * pr[lo] * e * e * pr[lo] <= n) {
            cnt += max(0, lo - i);
        }
    }
    cout << cnt << "\n";
    return 0;
}
