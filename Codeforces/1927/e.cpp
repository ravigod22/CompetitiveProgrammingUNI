#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        int l = 1;
        int r = n;
        vector<int> ans(n);
        for (int i = 0; i < k; ++i) {
            for (int j = i; j < n; j += k) {
                if (i & 1) ans[j] = r--;
                else ans[j] = l++;
            }
        }
        for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
    }
    return 0;
}

