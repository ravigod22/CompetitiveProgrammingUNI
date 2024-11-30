#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        if (n % m == 0) {
            cout << 0 << "\n";
            continue;
        }
        int cntn = 0;
        while (n % 2 == 0) cntn++, n /= 2;
        int cntm = 0;
        while (m % 2 == 0) cntm++, m /= 2;
        if (n % m == 0) {
            cout << max(cntn - cntm, 0) << "\n";
        }
        else cout << -1 << "\n";
    }
    return 0;
}
