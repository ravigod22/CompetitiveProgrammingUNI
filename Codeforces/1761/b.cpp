#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            cnt[x] = 1;
        }
        int e = accumulate(cnt.begin(), cnt.end(), 0);
        if (e == 2) cout << n / 2 + 1 << "\n";
        else cout << n << "\n";
    }
    return 0;
}
