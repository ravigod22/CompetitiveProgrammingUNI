#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        int cnt = 0;
        for (int i = n; i > 0; --i) {
            for (int times = 0; times <= (i == n ? 1 : 2); ++times) {
                if (k > 0) {
                    k -= i;
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
