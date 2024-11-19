#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        int result = inf;
        for (int i = 0; i < n; ++i) {
            int ans = 0;
            if (i == 0) {
                ans = max(a[0], a[1]);
            }
            else if (i + 1 == n) {
                ans = max(a[n - 1], a[n - 2]);
            }
            else {
                ans = min(max(a[i + 1], a[i]), max(a[i], a[i - 1]));
            }
            result = min(result, ans);
        }
        cout << result - 1 << "\n";
    }
    return 0;
}

