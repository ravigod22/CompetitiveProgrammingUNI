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
        bool can = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] < 2 * a[i - 1] && a[i - 1] < 2 * a[i]) can = 1;
        }
        cout << (can ? "YES" : "NO") << "\n";
    }
    return 0;
}
