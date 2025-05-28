#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        auto solve = [&] (vector<int> b, int target) -> bool {
            vector<int> left, right;
            for (int e : b) {
                if (e <= target) left.push_back(e);
                else right.push_back(e);
            }
            sort(left.rbegin(), left.rend());
            sort(right.begin(), right.end());
            int lim = (n + 1) / 2;
            int lenleft = (n + 1) / 2, lenright = n / 2;
            bool can;
            if (left.size() > lenleft) {
                int remain = (int)left.size() - lenleft;
                while (remain) {
                    int u = -left.back();
                    left.pop_back();
                    if (u <= target) break;
                    remain--;
                }
                can = (remain == 0);
            }
            else {
                int remain = (int)right.size() - lenright;
                while (remain) {
                    int u = -right.back();
                    right.pop_back();
                    if (u > target) break;
                    remain--;
                }
                can = (remain == 0);
            }
            return can;
        };
        bool c1 = solve(a, a[0]);
        a[0] *= -1;
        bool c2 = solve(a, a[0]);
        cout << (c1 || c2 ? "YES" : "NO") << "\n";
    }
    return 0;
}


