#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m, k; cin >> n >> m >> k;
        int ans = -1;
        for (int i = 1; i <= m; ++i) {
            int tmp = k / i;
            if (k == i * tmp && tmp <= n) continue;
            ans = i;
        }
        vector<int> result(n, ans);
        if (ans == -1) {
            cout << "N\n";
        }
        else {
            cout << "S";
            for (auto e : result) cout << " " << e;
            cout << "\n";
        }
    }
    return 0;
}
