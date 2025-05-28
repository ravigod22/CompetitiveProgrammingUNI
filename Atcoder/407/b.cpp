#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y; cin >> x >> y;
    int a = 0, b = 0, c = 0;
    for (int i = 1; i <= 6; ++i) {
        for (int j = 1; j <= 6; ++j) {
            if (i + j >= x && abs(i - j) >= y) c += 1;
            if (i + j >= x) a += 1;
            if (abs(i - j) >= y) b += 1;
        }
    }
    cout << fixed << setprecision(12);
    long double ans = 1.0 * (a + b - c) / 36;
    cout << ans << "\n";
    return 0;
}

