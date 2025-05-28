#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 f(i64 n) {
    if (n < 1) return 1;
    int last = -1;
    for (int i = 60; i >= 0; --i) {
        if ((n >> i) & 1) {
            last = i;
            break;
        }
    }
    return (1LL << (last + 1)) - 1;
}

int solve(i64 n, i64 find_pos) {
    if (n < 2) return n;
    i64 L1 = 1, R1 = f(n / 2);
    i64 mid = R1 + 1;
    i64 L2 = mid + 1, R2 = f(n);
    if (find_pos <= R1) return solve(n / 2, find_pos);
    else if (find_pos == mid) return n % 2;
    else return solve(n / 2, find_pos - mid);
}

int main() {
    i64 n, l, r; cin >> n >> l >> r;
    int ans = 0;
    for (i64 i = l; i <= r; ++i) {
        ans += solve(n, i);
    }
    cout << ans << "\n";
    return 0;
}
