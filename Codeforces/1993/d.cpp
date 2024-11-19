#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        if (k >= n) {
            cout << (n & 1 ? a[n / 2] : a[(n - 1) / 2]) << "\n";
            continue;
        }
    }
    return 0;
}
