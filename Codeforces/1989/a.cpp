#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int x, y; cin >> x >> y;
        if (y >= -1) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    return 0;
}
