#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n;
        long long m;
        cin >> n >> m;
        vector<int> a(n);
        vector<long long> prefix(n + 1, 0);
        for (int& e : a) cin >> e;
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + 0ll + a[i];
        sort(a.begin(), a.end());
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            int j = i;
            int aux = a[j];
            vector<int> tmp;
            while (aux + 1 >= a[j] && j < n) {
                tmp.emplace_back(j + 1);
                ++j;
            }
            for (auto e : tmp) cout << e << " "; 
            cout << "\n";
            int l = tmp.size();
            if (l == 1) {
                if (a[tmp.back() - 1] <= m) ans = max(ans, 1ll * a[tmp.back() - 1]);
                continue;
            }
            auto pre = [&] (int l, int r) -> long long {
                return prefix[r] - prefix[l - 1];
            };
            // 1-index
            for (int k = 0; k < l - 1; ++k) {
                int other = tmp[k];
                int lo = tmp[k];
                int hi = tmp[l -1];
                while (lo < hi) {
                    int mid = (lo + hi + 1) / 2;
                    if (pre(mid, other - 1) <= m) lo = mid;
                    else hi = mid - 1;
                }
                if (pre(lo, other - 1) <= m) ans = max(ans, pre(lo, other - 1));
            }
            tmp.clear();
        }
        cout << ans << "\n";
    }
    return 0;
}

