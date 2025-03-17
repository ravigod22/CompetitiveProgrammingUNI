#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u128 = unsigned __int128;
i64 found(i64 y, i64 N) {
    i64 lo = 0;
    i64 hi = 1e12;
    while (lo < hi) {
        i64 mid = (lo + hi) / 2;
        if ((u128)mid * mid * mid >= (u128)y * y * y + N) hi = mid;
        else lo = mid + 1;
    }
    if ((u128)lo * lo * lo == (u128)(y * y * y + N)) return lo;
    return -1;
}

int main() {
    i64 n; cin >> n;
    for (int y = 1; y <= 6e6; ++y) {
        i64 ans = found(y, n);
        if (ans > 0 && ans > y) {
            cout << ans << " " << y << "\n";
            return 0;
        } 
    }
    cout << -1 << "\n";
    return 0;
}



