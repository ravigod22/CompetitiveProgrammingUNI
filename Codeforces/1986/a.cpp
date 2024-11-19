#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
       int x1, x2, x3; cin >> x1 >> x2 >> x3;
       int tmp = x1 + x2 + x3;
       auto f = [&] (int x, int a, int b, int c) -> int {
            return abs(a - x) + abs(b - x) + abs(c - x);
       };
        cout << min({f(x1, x1, x2, x3), f(x2, x1, x2, x3), f(x3, x1, x2, x3)}) << "\n";
    }
    return 0;
}
