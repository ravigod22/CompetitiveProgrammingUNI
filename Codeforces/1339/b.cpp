#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        sort(a.begin(), a.end());
        vector<int> ans;
        if (n & 1) {
            ans.emplace_back(a[n / 2]);
            for (int i = n - 1; i > n / 2; --i) {
                ans.emplace_back(a[i]);
                ans.emplace_back(a[n - i - 1]);
            }
            reverse(ans.begin() + 1, ans.end());
        }
        else {
            for (int i = n - 1; i >= n / 2; --i) {
                ans.emplace_back(a[i]);
                ans.emplace_back(a[n - i - 1]);
            }
            reverse(ans.begin(), ans.end());
        }
        for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
    }
    return 0;
}


