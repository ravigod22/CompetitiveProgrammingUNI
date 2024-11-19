#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int x, y;
        cin >> x >> y;
        int cnt = 0;
        for (int i = 0; i < 30; ++i) {
            if (((x >> i) & 1) == ((y >> i) & 1)) cnt++;
            else break;
        }
        cout << (1 << cnt) << "\n";
    }
    return 0;
}
