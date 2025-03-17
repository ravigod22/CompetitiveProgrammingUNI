#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> cnt(maxn, -1);
        for (int i = 1; i <= n; ++i) {
            int x; cin >> x;
            cnt[x] = max(cnt[x], i);
        }
        int ans = -1;
        for (int i = 1; i <= 1000; ++i) {
            for (int j = i; j <= 1000; ++j) {
                if (cnt[i] == -1 || cnt[j] == -1) continue;
                if (gcd(i, j) == 1) ans = max(ans, cnt[i] + cnt[j]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

