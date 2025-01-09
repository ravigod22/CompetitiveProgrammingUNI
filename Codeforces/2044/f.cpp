#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m, q; cin >> n >> m >> q;
    vector<int> a(n), b(m);
    for (int& e : a) cin >> e;
    for (int& e : b) cin >> e;
    i64 accA = accumulate(a.begin(), a.end(), 0LL);
    i64 accB = accumulate(b.begin(), b.end(), 0LL);
    map<i64, bool> mp1;
    map<i64, bool> mp2;
    for (int e : a) {
        i64 tmp = accA - e;
        mp1[tmp] = 1;
    }
    for (int e : b) {
        i64 tmp = accB - e;
        mp2[tmp] = 1;
    }
    for (int i = 0; i < q; ++i) {
        int x; cin >> x;
        bool neg = (x < 0);
        int tmp = abs(x);
        bool exist = false;
        for (int j = 1; j * j <= tmp; ++j) {
            if (tmp % j == 0) {
                for (int e : {j, tmp / j}) {
                    i64 d1 = 1LL * e;
                    i64 d2 = 1LL * tmp / e;
                    if (neg) {
                        if (mp1.count(-d1) && mp2.count(d2)) exist = true;
                        if (mp1.count(d1) && mp2.count(-d2)) exist = true;
                    }
                    else {
                        if (mp1.count(d1) && mp2.count(d2)) exist = true;
                        if (mp1.count(-d1) && mp2.count(-d2)) exist = true;
                    }
                }
            }
        }
        cout << (exist ? "YES" : "NO") << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

