#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl
const int mod = 998244353;

int binpow(int a, int e) {
    int res = 1;
    while (e) {
        if (e & 1) res = (1LL * res * a) % mod;
        a = (1LL * a * a) % mod;
        e /= 2;
    }
    return res;
}

pair<int, int> compare(pair<int, int> a, pair<int, int> b) {
    if (a.first < a.second) swap(a.first, a.second);
    if (b.first < b.second) swap(b.first, b.second);
    return max(a, b);
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for (int& e : p) cin >> e;
    for (int& e : q) cin >> e;
    vector<int> ans(n, 0);
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


