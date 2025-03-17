#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int lim = (n * (n - 1)) / 2;
        vector<int> a(lim);
        for (int & e : a) cin >> e;
        sort(a.begin(), a.end());
        vector<int> ans;
        for (int i = 0, k = n - 1; i < lim && k; k--) {
            ans.emplace_back(a[i]);
            i += k;
        }
        ans.emplace_back(1e9);
        for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
    }
    return 0;
}


