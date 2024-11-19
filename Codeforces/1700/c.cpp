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
        long long ans = 0;
        long long prefix = a[0];
        for (int i = 1; i < n; ++i) {
            if (a[i - 1] < a[i]) ans += 0ll + a[i] - a[i - 1];
            else {
                ans += 0ll + a[i - 1] - a[i];
                prefix -= 0ll + a[i - 1] - a[i];
            }
        }
        cout << ans + abs(prefix) << "\n";
    }
    return 0;
}

