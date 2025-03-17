#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> cnt(n + 1, 0);
        for (int& e : a) cin >> e, cnt[e]++;
        vector<int> ans;
        bool change = true;
        for (int i = 0; i <= n; ++i) {
            if (cnt[i] > 1) ans.emplace_back(i);
            else if (cnt[i] == 1) {
                if (change) ans.emplace_back(i);
                change ^= 1;
            }
        }
        int mext = 0;
        sort(ans.begin(), ans.end());
        for (int i = 0; i < (int)ans.size(); ++i) {
            if (ans[i] <= mext) mext++;
        }
        cout << mext << "\n";
    }
    return 0;
}
