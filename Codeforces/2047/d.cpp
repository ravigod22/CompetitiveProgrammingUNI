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
        vector<int> a(n);
        for (int& e : a) cin >> e;
        vector<int> ans;
        multiset<int> tmp;
        for (int i = 0; i < (int)a.size(); ++i) {
            while (!ans.empty() && ans.back() > a[i]) {
                int aux = ans.back();
                ans.pop_back();
                tmp.emplace(aux + 1);
            }
            for (int e : tmp) {
                a.emplace_back(e);
            }
            ans.emplace_back(a[i]);
            tmp.clear();
        }
        assert (ans.size() == n);
        for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
    }
    return 0;
}



