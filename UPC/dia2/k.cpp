#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        int r, c; cin >> r >> c;
        if (r == -1) break;
        if (r == 1 && c == 1) {
            cout << 26 * 2 + 13 << "\n";
            continue;
        }
        if (c == 1) {
            r--;
            cout << 26 * 2 + 13 * (r + 1) + 38 * r * 2 << "\n";
            continue;
        }
        if (r == 1) {
            c--;
            cout << 26 * 2 + 13 * (c + 1) + 38 * c * 2 << "\n";
            continue;
        }
        bool odd = ((r & 1) && (c & 1));
        int ans = 26 * 2 + 13 * r * c + 38 * r * c + (odd ? 38 : 0);
        cout << ans << "\n";
    }
    return 0;
}
