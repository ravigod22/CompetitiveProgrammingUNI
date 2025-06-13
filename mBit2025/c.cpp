#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<i64> cnt(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> cnt[i];
    }
    vector<int> ban(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] > i) ban[i] = 1;
    }
    i64 res = 0;
    i64 sum = 0;
    for (int i = n; i > 0; --i) {
        // cout << "pos " << i << endl;
        if (ban[i]) continue;
        cnt[i] += sum;
        i64 op = cnt[i] / i;
        // cout << "op -> " << op << endl;
        // cout << "sum -> " << sum << endl;
        res += op;
        sum += op;
    }
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
