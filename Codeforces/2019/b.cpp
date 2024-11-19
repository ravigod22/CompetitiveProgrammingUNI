#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

void solve() {
    int n, q; cin >> n >> q;
    vector<int> x(n);
    vector<ll> r(q);
    for (int& e : x) cin >> e;
    for (auto& e : r) cin >> e;
    vector<ll> times(n);
    times[0] = n - 1;
    ll tmp = n - 2;
    map<ll, ll> cnt;
    cnt[n - 1]++;
    for (int i = 1; i < n; ++i) {
        times[i] = times[i - 1] + tmp;
        tmp -= 2;
        cnt[times[i]]++;
    }
    ll aux = 0;
    for (int i = 1; i < n; ++i) {
        ll dis = x[i] - x[i - 1] - 1;
        ll mintimes = min(times[i], times[i - 1]);
        cnt[mintimes - aux] += dis;
        if (n & 1) {
            if (i < n / 2) aux++;
            else if (i > n / 2) aux--;
        }
        else {
            if (i < n / 2) aux++;
            else if (i >= n / 2) aux--;
        }
    }
    for (int i = 0; i < q; ++i) {
        cout << cnt[r[i]] << " \n"[i + 1 == q];
    }
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


