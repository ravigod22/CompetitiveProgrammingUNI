#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4;

int memox[2 * maxn + 1], memoy[2 * maxn + 1], memo[2 * maxn + 1];

int main() {
    int n, x, y; cin >> n >> x >> y;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    int *dpx = memox + maxn, *dpy = memoy + maxn, *dptmp = memo + maxn;
    dpx[a[0]] = dpy[0] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = -maxn; j <= maxn; ++j) dptmp[j] = 0;
        int e = a[i];
        if (i % 2 == 0) {
            for (int j = -maxn; j + e <= maxn; ++j) {
                dptmp[j + e] |= dpx[j];
                dptmp[j] |= dpx[j + e];
            }
            swap(dptmp, dpx);
        }
        else {
            for (int j = -maxn; j + e <= maxn; ++j) {
                dptmp[j + e] |= dpy[j];
                dptmp[j] |= dpy[j + e];
            }
            swap(dptmp, dpy);
        }
    }
    cout << (dpx[x] && dpy[y] ? "Yes" : "No") << "\n";
    return 0;
}
