#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int xc, yc, k; cin >> xc >> yc >> k;
        int tmp = 1e6;
        int tmp2 = 1e8;
        if (k & 1) {
            cout << xc * k << " " << yc * k << "\n";
            k--;
        }
        else {
            cout << tmp2 + xc * k << " " << -tmp2 << "\n";
            cout << -tmp2 << " " << tmp2 + yc * k << "\n";
            k -= 2;
        }
        for (int i = 0; i < k / 2; ++i) {
            cout << tmp << " " << tmp << "\n";
            cout << -tmp << " " << -tmp << "\n";
            tmp++;
        }
    }
    return 0;
}
