#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int x1, x2, y1, y2; cin >> x1 >> x2 >> y1 >> y2;
        if (y1 > y2) {
            if (x1 > x2) cout << "YES\n";
            else cout << "NO\n";
        }
        else {
            if (x1 > x2) cout << "NO\n";
            else cout << "YES\n";
        }
    }
    return 0;
}
