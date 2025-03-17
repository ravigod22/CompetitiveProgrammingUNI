#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    int n; cin >> n;
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        ans = lcm(ans, i);
    }
    cout << ans << "\n";
    return 0;
}
