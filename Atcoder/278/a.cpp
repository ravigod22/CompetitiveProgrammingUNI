#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        if (k >= n) {
            for (int i = 0; i < n; ++i) {
                cout << 0 << " \n"[i + 1 == n];
            }
        }
        else {
            for (int i = k; i < n; ++i) {
                cout << a[i] << " ";
            }
            for (int i = 0; i < k; ++i) {
                cout << 0 << " \n"[i + 1 == k];
            }
        }
    }
    return 0;
}
