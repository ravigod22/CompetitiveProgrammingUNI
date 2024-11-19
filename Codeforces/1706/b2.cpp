#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> G[n + 1];
        vector<int> ans(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            G[a[i]].emplace_back(i + 1);
        }
        for (int i = 1; i <= n; ++i) {
            if (G[i].size() < 1) continue;
            vector<int> tmp = G[i];
            int cnt = 1;
            int aux = tmp[0];
            for (int j = 1; j < tmp.size(); ++j) {
                if ((tmp[j] & 1) != (aux & 1)) {
                    cnt++;
                    aux = tmp[j];
                } 
            }
            ans[i] = cnt;
        }
        for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n]; 
    }
    return 0;
}


