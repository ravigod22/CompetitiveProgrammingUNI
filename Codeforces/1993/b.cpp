#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> odd;
        vector<int> even;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if (x & 1) odd.emplace_back(x);
            else even.emplace_back(x);
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        if (even.size() == n || odd.size() == n) {
            cout << 0 << "\n";
            continue;
        }
        long long tmp = 1LL * odd.back();
        int ans = 0;
        for (int i = 0; i < even.size(); ) {
            if (tmp < 1LL * even[i]) {
                tmp += 1LL * even[i];
                ans++;
            }
            else {
                tmp += 1LL * even[i];
                i++;
                ans++;
            }
        }
        ans = min(ans, (int)even.size() + 1);
        cout << ans << "\n";
    }
    return 0;
}
