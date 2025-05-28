#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        if (n == 2) {
            cout << "2 1" << "\n";
            continue;
        }
        auto is_prime = [&] (int x) -> bool {
            for (int i = 2; i * i <= x; ++i) {
                if (x % i == 0) return false;
            }
            return true;
        };
        int num = 0;
        for (int i = n; i >= n / 3; --i) {
            if (i & 1) {
                if (is_prime((i + 1) / 2)) {
                    num = i;
                    break;
                }
            }
        }
        assert (num > 0);
        vector<bool> used(n + 1, 0);
        int p = 1, q = num;
        vector<int> ans;
        while (p != (num + 1) / 2) {
            used[p] = used[q] = 1;
            ans.push_back(p++);
            ans.push_back(q--);
        }
        used[(num + 1) / 2] = 1;
        ans.push_back((num + 1) / 2);
        for (int i = 1; i <= n; ++i) {
            if (used[i]) continue;
            ans.push_back(i);
        }
        assert (ans.size() == n);
        for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
    }
    return 0;
}
