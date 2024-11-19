#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (auto& e : a) cin >> e;
    sort(a.begin(), a.end());
    long long sum = accumulate(a.begin(), a.end(), 0LL);
   auto f = [&] (ll x, vector<ll> b) -> int{
        b = a;
        long long tmp = sum + x;
        long long aux = (tmp + 2LL * n - 1) / (2 * n);
        int cnt = 0;
        b[n - 1] += x;
        for (int i = 0; i < n; ++i) {
            if (b[i] < aux) cnt++;
        }
        return cnt;
    };
    ll lo = 0;
    ll hi = 1e16;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (f(mid, a) >= n / 2 + 1) hi = mid;
        else lo = mid + 1;
    }
    if (f(lo, a) >= n / 2 + 1) cout << lo << "\n";
    else cout << -1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}


