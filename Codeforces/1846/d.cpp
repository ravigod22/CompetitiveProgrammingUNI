#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);
    int tt; cin >> tt;
    while (tt--) {
        int n, d, h; cin >> n >> d >> h;
        vector<int> y(n);
        for (int& e : y) cin >> e;
        int l = 0;
        double ans = 0;
        while (l < n) {
            int r = l + 1;
            while (r < n && y[r] - y[r - 1] < h) {
                double deltax = 1.0 * (y[r] - y[r - 1]);
                ans += (1.0 * d * (1.0 * h - deltax) * deltax) / h + (deltax * deltax * d) / (2 * h);
                r++;
            }
            ans += (1.0 * d * h) / 2;
            l = r;
        }
        cout << ans << "\n";
    }
    return 0;
}

