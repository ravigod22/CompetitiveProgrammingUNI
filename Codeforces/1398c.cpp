#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int sum = 0;
        i64 ans = 0;
        map<int, int> cnt;
        cnt[0] = 1;
        for (int i = 1; i <= n; ++i) {
            char x; cin >> x;
            int tmp = x - '0';
            sum += tmp - 1;
            ans += cnt[sum];
            cnt[sum]++;
        }
        cout << ans << "\n";
    }
    return 0;
}
