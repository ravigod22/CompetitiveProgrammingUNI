#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        if (n % 2 == 0) {
            cout << -1 << "\n";
        }
        else {
            int tmp = n - n / 2;
            for (int i = 0, j = 1; i < (n / 2); ++i, j++) {
                cout << j << " ";
            }
            for (int i = 0, j = n; i < tmp; ++i, j--) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
