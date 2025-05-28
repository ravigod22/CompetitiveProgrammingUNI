#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int solve(int a, int b) {
    if (a == 1) return b - 1;
    return b / a + solve(b % a, a);
}

int main() {
    int n; cin >> n;
    int ans = n - 1;
    for (int i = 1; i <= n; ++i) {
        if (gcd(i, n) != 1) continue;
        ans = min(ans, solve(i, n));
    }
    cout << ans << "\n";
    return 0;
}
