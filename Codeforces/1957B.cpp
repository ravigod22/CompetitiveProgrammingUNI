#include <bits/stdc++.h>
using namespace std;
int cnt(int k) {
    int p = 0;
    for (int i = 30; i >= 0; --i) {
        if (k & (1 << i)) p++;
    }
    return p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        if (n == 1) {
            cout << k << "\n";
            continue;
        }
        if (k == 1) {
            cout << 1;
            n--;
            for (int i = 0; i < n; ++i) {
                cout << " " << 0;
            }
            cout << "\n";
            continue;
        }
        int num = 0;
        int ind = 0;
        for (int i = 31; i >= 0; --i) {
            if (k & (1 << i)) {
                num = (1 << i) - 1;
                ind = i;
                break;
            }
        }
        if (n > 2) {
            cout << num << " " << k - num;
            for (int i = 0; i < n - 2; ++i) cout << " " << 0;
            cout << "\n";
        }
        else {
            cout << num << " " << k - num << "\n";
        }
    }
    return 0;
}
