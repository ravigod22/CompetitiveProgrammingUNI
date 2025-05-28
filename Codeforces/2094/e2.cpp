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
    int cnt[30] {0};
    for (int e : a) {
        for (int j = 0; j < 30; ++j) {
            cnt[j] += ((e >> j) & 1);
        }
    }
    i64 ans = 0;
    for (int e : a) {
        i64 sum = 0;
        for (int j = 0; j < 30; ++j) {
            sum += 1LL * ((e >> j) & 1 ? n - cnt[j] : cnt[j]) * (1 << j);
        }
        ans = max(ans, sum);
    }
    cout << ans << "\n";
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



