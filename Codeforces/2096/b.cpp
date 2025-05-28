#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n, k; cin >> n >> k;
    vector<int> l(n), r(n);
    for (int& e : l) cin >> e;
    for (int& e : r) cin >> e;
    i64 sum = 0;
    for (int i = 0; i < n; ++i) sum += 1LL * max(l[i], r[i]);
    vector<int> mine;
    for (int i = 0; i < n; ++i) mine.emplace_back(min(l[i], r[i]));
    sort(mine.rbegin(), mine.rend());
    for (int i = 0; i < k - 1; ++i) sum += 0LL + mine[i] - 1;
    sum += 1LL * k;
    cout << sum << "\n";
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


