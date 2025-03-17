#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        int ans = *max_element(a.begin(), a.end());
        for (int i = 1; i < n; ++i) {
            vector<int> tmp = a;
            int op = k;
            for (int j = i; j > 0; j--) {
                if (tmp[j] >= tmp[j - 1]) {
                    int dis = tmp[j] - tmp[j - 1] + 1;
                    tmp[j - 1] += min(dis, op);
                    op -= min(dis, op);
                }
            }
            int maxtmp = *max_element(tmp.begin(), tmp.end());
            ans = max(ans, maxtmp);
        }
        cout << ans << "\n";
    }
    return 0;
}
