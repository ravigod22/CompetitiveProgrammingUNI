#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int x, y, a; cin >> x >> y >> a;
        a %= (x + y);
        if (a < x) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}

