#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    i64 n; cin >> n;
    i64 tmp = n;
    i64 ans = 0;
    for (int i = 2; 1LL * i * i <= tmp; ++i) {
        if (tmp % i == 0) {
            while (tmp % i == 0) tmp /= i;
            ans = max(ans, 1LL * i);
        }
    }
    if (tmp > 1) ans = max(ans, tmp);
    cout << ans << "\n";
    return 0;
}
