#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        for (int i = n; i <= n + 500; ++i) {
            int tmp = i;
            int sum = 0;
            while (tmp) {
                sum += tmp % 10;
                tmp /= 10;
            }
            if (sum % k == 0) {
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}
