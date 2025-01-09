#include <bits/stdc++.h>
using namespace std;

const int maxe = 2e6 + 5;
const int mod = 998244353;
int cnt[maxe];

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<pair<int, int>> x(n);
        for (auto &e : x) cin >> e.first;
        for (auto &e : x) cin >> e.second;
        int m; cin >> m;
        vector<pair<int, int>> y(m);
        for (auto &e : y) cin >> e.first;
        for (auto &e : y) cin >> e.second;
        for (auto &e : x) {
            cnt[e.first] += e.second;
        }
        for (auto &e : y) {
            cnt[e.first] -= e.second;
        }
        bool can = true;
        int tmp = 0;
        for (int i = 2; i < maxe && can; ++i) {
            if (cnt[i] < 0) can = false;
            else if (cnt[i] > 0) tmp++;
        }
        cout << (can ? binpow(2, tmp) : 0) << "\n";
    }
    return 0;
}
