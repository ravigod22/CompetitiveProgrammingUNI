#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        map<int, i64> cnt;
        auto f = [&] (auto&& self, int l, int r) -> i64 {
            int dis = r - l + 1;
            if (l > r) return 0;
            if (dis < k) return 0;
            int mid = (l + r) / 2;
            if (cnt.count(dis)) return cnt[dis];
            i64 ans = 0;
            if (dis & 1) {
                ans++;
                ans += self(self, l, mid - 1);
                ans += self(self, mid + 1, r);
            }
            else {
                ans += self(self, l, mid);
                ans += self(self, mid + 1, r);
            }
            cnt[dis] = ans;
            return ans;
        };
        i64 p = f(f, 1, n);
        map<int, i64> dp;
        auto dfs = [&] (auto&& self, int l, int r) -> i64 {
            int dis = r - l + 1;
            if (l > r) return 0; 
            if (dis < k) return 0;
            if (dp.count(dis)) return dp[dis] + 1LL * cnt[dis] * (0LL + l - 1);
            int mid = (l + r) / 2;
            i64 ans = 0;
            if (dis & 1) {
                ans += 1LL * mid;
                ans += self(self, l, mid - 1);
                ans += self(self, mid + 1, r);
            }
            else {
                ans += self(self, l, mid);
                ans += self(self, mid + 1, r);
            }
            dp[dis] = ans;
            return ans;
        };
        cout << dfs(dfs, 1, n) << "\n";
    }
    return 0;
}


