#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> cnt(n + 1, 0);
        vector<int> ans(n + 1, 0);
        vector<int> last(n + 1, -1);
        vector<int> a(n);
        for (int& e : a) cin >> e;
        for (int i = 0; i < n; ++i) {
            if (last[a[i]] == -1) {
                cnt[a[i]]++;
                last[a[i]] = i;
            }
            else {
                int dis = i - last[a[i]] - 1;
                if (dis % 2 == 0) {
                    cnt[a[i]]++;
                    last[a[i]] = i;
                }
                else if (dis & 1 && i + 1 < n && a[i + 1] != a[i]){
                    ans[a[i]] = max(ans[a[i]], cnt[a[i]]);
                    last[a[i]] = i;
                    cnt[a[i]] = 1;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            ans[i] = max(ans[i], cnt[i]);
            cout << ans[i] << " \n"[i == n];
        }
    }
    return 0;
}

