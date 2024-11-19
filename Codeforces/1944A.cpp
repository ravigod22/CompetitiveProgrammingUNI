#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        cout << (k >= n - 1 ? 1 : n) << "\n";
    }
    return 0;
}
