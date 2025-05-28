#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&] (int i, int j) {
            return a[i] < a[j];
        });
        int p = 0;
        int ans = n / 2;
        while (p < n) {
            int q = p + 1;
            while (q < n && ord[q] > ord[q - 1]) {
                q++;
            }
            int op = max(p,n - q);
            ans = min(ans, op);
            p = q;
        }
        cout << ans << "\n";
    }
    return 0;
}
