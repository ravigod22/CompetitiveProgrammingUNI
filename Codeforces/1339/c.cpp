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
        if (n == 1) {
            cout << 0 << "\n";
            continue;
        }
        int ans = 0;
        int aux = a[0];
        for (int i = 1; i < n; ++i) {
            if (a[i] < aux) {
                int tmp = aux - a[i];
                ans = max(ans, 32 - __builtin_clz(tmp));
            }
            else {
                aux = a[i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}


