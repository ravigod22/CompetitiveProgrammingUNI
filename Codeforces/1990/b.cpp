#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, x, y; cin >> n >> x >> y;
        vector<int> a(n + 1, 0);
        if (y & 1) {
            int tmp = 1;
            for (int i = 1; i < y; ++i) {
                a[i] = tmp;
                tmp *= -1;
            }
        }
        else {
            int tmp = -1;
            for (int i = 1; i < y; ++i) {
                a[i] = tmp;
                tmp *= -1;
            }
        }
        int tmp2 = -1;
        for (int i = x + 1; i <= n; ++i) {
            a[i] = tmp2;
            tmp2 *= -1;
        }
        for (int i = 1; i <= n; ++i) {
            if (a[i] == 0) a[i] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            cout << a[i] << " \n"[i == n];
        }
    }
    return 0;
}
