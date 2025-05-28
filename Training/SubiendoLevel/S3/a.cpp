#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    vector<i64> prefix(n + 1);
    for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + a[i];
    while (q--) {
        int l, r; cin >> l >> r;
        cout << prefix[r] - prefix[l] << "\n";
    }
    return 0;
}
