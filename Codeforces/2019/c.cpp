#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for (auto& e : a) cin >> e;
    sort(a.begin(), a.end());
    vector<ll> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + a[i];
    auto f = [&] (int box) -> long long {
        ll ans = 0;
        vector<ll> tmp = a;
        ll aux = (box == n ? 0 : a[n - box - 1]);
        ll sum = 0;
        ll maxe = 0;
        for (int i = n - box; i < n; ++i) {
            tmp[i] -= aux;
            sum += tmp[i];
            maxe = max(maxe, tmp[i]);
        }
        ans = maxe * box - sum;
        return ans;
    }; 
    int lo = 1;
    int hi = n;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (f(mid) <= k) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << "\n";
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


