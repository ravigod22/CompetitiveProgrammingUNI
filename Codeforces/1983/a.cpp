#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        for (int i = 0; i < n; ++i) {
            cout << i + 1 << " \n"[i + 1 == n];
        }
    }
    return 0;
}
