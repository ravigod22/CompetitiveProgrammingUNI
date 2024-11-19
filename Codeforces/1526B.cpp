#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int x;
        cin >> x;
        if (x >= 1100) {
            cout << "YES\n";
            continue;
        }
        bool ans = false;
        for (int i = 0; 111 * i <= x; ++i) {
            int tmp = x - (111 * i);
            if (tmp % 11 == 0) {
                ans = true;
            }
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}
