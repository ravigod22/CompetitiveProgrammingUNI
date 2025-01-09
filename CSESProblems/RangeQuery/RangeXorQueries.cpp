#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<int> x(n);
    for (int& e : x) cin >> e;
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] ^ x[i];
    while (q--) {
        int l, r; cin >> l >> r;
        l--;
        cout << (prefix[r] ^ prefix[l]) << "\n";
    }
    return 0;
}
