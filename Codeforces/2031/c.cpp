#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        if ((n & 1) && n < 27) {
            cout << -1 << "\n";
            continue;
        }
        if (n % 2 == 0) {
            for (int i = 1; i <= n; ++i) cout << (i + 1) / 2 << " \n"[i == n];
        }
        else if (n >= 27) {
            vector<int> ans(n + 1, 0);
            ans[1] = ans[10] = ans[26] = 1;
            ans[23] = ans[27] = 2;
            int p = 3;
            for (int i = 1; i <= n; ) {
                if (ans[i] == 0) {
                    ans[i] = ans[i + 1] = p;
                    p++;
                    i += 2;
                }
                else i++;
            }
            for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
        }
    }
    return 0;
}
