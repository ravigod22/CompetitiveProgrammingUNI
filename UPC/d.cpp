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
    string s;
    while (true) {
        cin >> s;
        if (s == "*") break;
        int n = s.size();
        if (s[0] == 'N') {
            cout << -1 << "\n";
            continue;
        }
        long long ans = 1;
        bool could = true;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'Y') ans = lcm(ans, i + 1);
        }
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'Y') {
                if (ans % (i + 1)) {
                    could = false;
                    break;
                }
            }
            else {
                if (ans % (i + 1) == 0) {
                    could = false;
                    break;
                }
            }
        }
        if (!could) ans = -1;
        cout << ans << "\n";
    }
    return 0;
}
