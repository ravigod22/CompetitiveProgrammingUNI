#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--) {
        int sum1 = 0;
        for (int i = 0; i < 9; ++i) {
            int x; cin >> x;
            sum1 += x;
        }
        int sum2 = 0;
        for (int i = 0; i < 8; ++i) {
            int x; cin >> x;
            sum2 += x;
        }
        cout << sum1 - sum2 + 1 << "\n";
    }
    return 0;
}
