#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<string> ans;
        for (int i = 0; i < n; ++i) {
            string s; cin >> s;
            if (k-- > 0) ans.emplace_back(s);
        }
        sort(ans.begin(), ans.end());
        for (auto e : ans) cout << e << "\n";
    }
    return 0;
}

