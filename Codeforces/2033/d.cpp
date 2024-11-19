#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<long long> pre(n + 1, 0);
    vector<int> dp(n + 1, 0);
    map<long long, int> last;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pre[i + 1] = pre[i] + a[i];
    }
    last[0] = 0;
    for (int i = 1; i <= n; ++i) {
        if (last.count(pre[i])) {
            dp[i] = max(dp[i - 1], 1 + dp[last[pre[i]]]);
        }
        else {
            dp[i] = dp[i - 1];
        }
        last[pre[i]] = i;
    }
    cout << dp[n] << "\n";
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


