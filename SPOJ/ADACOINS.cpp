#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    bitset<maxn> dp;
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        dp |= (dp << x);
    }
    vector<int> prefix(maxn);
    for (int i = 1; i < maxn; ++i) {
        prefix[i] = prefix[i - 1] + dp[i];
    }
    while (q--) {
        int l, r; cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << "\n";
    }
    return 0;
}
