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
        int result = 2e9;
        for (int i = 1; i < n; ++i) {
            result = min(result, max(a[i - 1], a[i]));
        }
        cout << result - 1 << "\n";
    }
    return 0;
}
