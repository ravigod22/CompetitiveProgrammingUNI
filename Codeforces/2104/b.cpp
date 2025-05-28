#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl



void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    vector<int> maxe(n);
    maxe[0] = a[0];
    for (int i = 1; i < n; ++i) {
        maxe[i] = max(maxe[i - 1], a[i]);
    }
    vector<i64> ans(n);
    i64 total = accumulate(a.begin(), a.end(), 0LL);
    i64 sum = 0;
    for (int i = n - 1, j = 0; i >= 0; --i, j++) {
        if (i) {
            ans[j] = sum + maxe[i];
        }
        else {
            ans[j] = total;
        }
        sum += a[i];
    }
    for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
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


