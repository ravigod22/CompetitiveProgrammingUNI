#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

const int N = 5e3 + 5;
int n;
i64 k;
i64 a[N];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    vector<i64> need;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 60; ++j) {
            if ((a[i] >> j) & 1) ans += 1;
            else need.push_back(1LL << j);
        }
    }
    sort(need.begin(), need.end());
    for (auto e : need) {
        if (e <= k) {
            k -= e;
            ans += 1;
        }
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


