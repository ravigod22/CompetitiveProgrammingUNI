#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int l, r; cin >> l >> r;
        int cnt = 0;
        while (r) {
            r /= 2;
            cnt++;
        }
        cout << cnt - 1 << "\n";
    }
    return 0;
}
