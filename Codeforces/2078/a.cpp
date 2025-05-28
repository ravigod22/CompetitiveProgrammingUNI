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
        vector<int> a(2 * n);
        for (int& e : a) cin >> e;
        sort(a.begin(), a.end());
        vector<i64> odd, even;
        for (int i = 0; i < n - 1; ++i) even.emplace_back(a[i]);
        for (int i = n - 1; i < 2 * n; ++i) odd.emplace_back(a[i]);
        i64 x = accumulate(odd.begin(), odd.end(), 0LL) - accumulate(even.begin(), even.end(), 0LL);
        even.emplace_back(x);
        for (int i = 1; i <= 2 * n + 1; ++i) {
            if (i & 1) {
                if (!odd.empty()) cout << odd.back() << " \n"[i == 2 * n + 1];
                odd.pop_back();
            }
            else {
                if (!even.empty()) cout << even.back() << " \n"[i == 2 * n + 1];
                even.pop_back();
            }
        }
    }
    return 0;
}
