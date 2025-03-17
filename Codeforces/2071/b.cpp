#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    i64 sum = 1LL * n * (n + 1) / 2;
    i64 root = sqrtl(sum);
    if (1LL * root * root == sum) {
        cout << - 1 << "\n";
        return;
    }
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 1);
    for (int i = 1; i <= n; ++i) {
        i64 sum1 = 1LL * i * (i + 1) / 2;
        i64 tmp = sqrtl(sum1);
        if (sum1 == tmp * tmp) {
            swap(ans[i], ans[i - 1]);
        }
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



