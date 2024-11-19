#include <bits/stdc++.h>
using namespace std;
const int coins[] = {1, 3, 6, 10, 15};

void solve() {
    int n;
    cin >> n;
    int tmp = n;
    bool remain = false;
    int result = 0;
    for (int i = 4; i >= 0; --i) {
        if (tmp % coins[i] == 0) {
            result += (tmp / coins[i]);
            break;
        }
        else {
            result += (tmp / coins[i]);
            tmp %= coins[i];
        }
    }
    cout << result << "\n";
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
