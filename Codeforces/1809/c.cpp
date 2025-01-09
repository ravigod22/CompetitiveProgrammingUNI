#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        int pos = 0;
        for (int i = 1; i <= n; ++i) {
            if (i * (i + 1) / 2 >= k) {
                pos = i;
                break;
            }
        }
        int remain = (pos * (pos + 1)) / 2 - k;
        vector<int> ans;
        if (remain) pos--;
        for (int i = 0; i < pos; ++i) ans.emplace_back(2);
        if (remain) ans.emplace_back(-(2 * remain - 1));
        while ((int)ans.size() < n) {
            ans.emplace_back(-1000);
        }
        for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
    }
    return 0;
}
