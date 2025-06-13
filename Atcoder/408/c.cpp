#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cnt[l] += 1;
        cnt[r + 1] -= 1;
    }
    for (int i = 1; i <= n; ++i) {
        cnt[i] += cnt[i - 1];
    }
    int ans = *min_element(cnt.begin(), cnt.begin() + n);
    cout << ans << "\n";
    return 0;
}
