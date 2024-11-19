#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        vector<int> b(n + 1);
        b[0] = a[0];
        b[n] = a[n - 1];
        for (int i = 1; i < n; ++i) {
            b[i] = lcm(a[i], a[i - 1]);
        }
        bool could = true;
        for (int i = 1; i <= n; ++i) {
            if (gcd(b[i], b[i - 1]) != a[i - 1]) could = false;
        }
        cout << (could ? "YES\n" : "NO\n");
    }
    return 0;
}
