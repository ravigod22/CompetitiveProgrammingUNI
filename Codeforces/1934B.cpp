#include <bits/stdc++.h>
using namespace std;
const int coins[] = {1, 3, 6, 10, 15};

void solve() {
    int n;
    cin >> n;
    bool remain = false;
    int ans = 2e9;
    for (int j = 4; j >= 0; --j) {
        int result = 0;
        int tmp = n;
        for (int i = j; i >= 0; --i) {
            if (tmp % coins[i] == 0) {
                result += (tmp / coins[i]);
                break;
            }
            else {
                result += (tmp / coins[i]);
                tmp %= coins[i];
            }
        }
        ans = min(result, ans);
    }    
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
