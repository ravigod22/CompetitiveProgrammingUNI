#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int rnd(double m, double n, double p) {
    double tmp = m * p / n;
    tmp += 0.5;
    return (int) tmp;
}

int main() {
    while (true) {
        int m, n; cin >> m >> n;
        if (n == -1) break;
        int p = rnd(m, n, 100);
        int b = rnd(m, n, 20);
        string ans(20, '-');
        for (int i = 0; i < b; ++i) ans[i] = '*';
        if (p < 10) {
            ans[9] = (p % 10) + '0';
        }
        else if (p < 100) {
            ans[9] = (p / 10) + '0';
            ans[10] = (p % 10) + '0';
        }
        else {
            ans[8] = '1';
            ans[9] = '0';
            ans[10] = '0';
        }
        if (p < 10) ans[10] = '%';
        else ans[11] = '%';
        cout << ans << "\n";
    }
    return 0;
}
