#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n - 2);
        for (int& e : a) cin >> e;
        bool can = true;
        for (int i = 1; i + 1 < n - 2; ++i) {
            if (a[i] == 0 && a[i - 1] == 1 && a[i + 1] == 1) can = false;
        }
        cout << (can ? "YES" : "NO") << "\n";
    }
    return 0;
}
