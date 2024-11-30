#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int mine = 1;
        while (n % mine == 0) mine++;
        string ans;
        for (int i = 0; i < n; ++i) {
            ans += (char)('a' + i % mine);
        }
        cout << ans << "\n";
    }
    return 0;
}
