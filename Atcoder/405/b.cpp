#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> cnt(m + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]] += 1;
    }
    
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        if (!cnt[i]) {
            cout << 0 << "\n";
            return 0;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        cnt[a[i]] -= 1;
        ans += 1;
        if (!cnt[a[i]]) break;
    }
    cout << ans << "\n";
    return 0;
}
