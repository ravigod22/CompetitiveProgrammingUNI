#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int r[3], c[3];
        int x, y;
        for (int i = 0; i < 3; ++i) {
            cin >> r[i] >> c[i];
        }
        cin >> x >> y;
        int R = (r[0] == r[1] ? r[0] : r[2]);
        int C = (c[0] == c[1] ? c[0] : c[2]);
        if ((R == 1 || R == n) && (C == 1 || C == n)) {
            cout << ((x == R || y == C) ? "YES" : "NO");
        }
        else {
            if ((R + C) % 2 == (x + y) % 2) {
                cout << (R % 2 == x % 2 ? "YES" : "NO");
            }
            else cout << "YES";
        }
        cout << "\n";
    }
    return 0;
}



