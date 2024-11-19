#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + 1ll * a[i];
        }
        int q; cin >> q;
        while (q--) {
            int l, r; cin >> l >> r;
            long long tmp = prefix[r] - prefix[l - 1];
            int dis = (r - l + 1);
            if (dis == k) {
                if (abs(tmp) % (1ll * k) == 0) cout << "Yes\n";
                else cout << "No\n";
            }
            else {
                int pl = l - 1;
                int pr = r - 1;
                if (1ll * a[pr - k] * k + 1ll * a[pr] * k == tmp) cout << "Yes\n";
                else cout << "No\n";
            }
        }
    }
    return 0;
}

