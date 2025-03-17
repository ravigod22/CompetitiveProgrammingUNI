#include <bits/stdc++.h>
using namespace std;

int main() {
    int x; cin >> x;
    int ans = 0;
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            ans += (x == i * j ? 0 : i * j);
        }
    }
    cout << ans << "\n";
    return 0;
}
