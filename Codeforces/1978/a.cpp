#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        int tmp = 0;
        for (int i = 0; i < n - 1; ++i) tmp = max(tmp, a[i]);
        cout << 1ll * (tmp + a[n - 1]) << "\n";
    }
    return 0;
}
