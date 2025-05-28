#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    i64 n; cin >> n;
    i64 lim = 1, cnt = 0;
    while (lim <= n) {
        lim *= 2;
        cnt++;
    }
    cnt--;
    i64 ans = 0;
    for (int i = 1; i <= cnt; ++i) {
        i64 pow = 1LL << i;
        i64 remain = n / pow;
        i64 R = sqrtl(remain);
        ans += max((R + 1) / 2, 0LL);
    }
    cout << ans << "\n";
    return 0;
}

