#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    set<int> cnt[105];
    for (int i = 0; i < m; ++i) {
        int k; cin >> k;
        vector<int> tmp;
        for (int j = 0; j < k; ++j) {
            int x; cin >> x;
            tmp.emplace_back(x);
        }
        for (int a = 0; a < k + 1; ++a) {
            for (int b = a + 1; b < k; ++b) {
                cnt[tmp[a]].emplace(tmp[b]);
                cnt[tmp[b]].emplace(tmp[a]);
            }
        }
        tmp.clear();
    }
    bool could = true;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i].size() != n - 1) could = false; 
    }
    cout << (could ? "Yes\n" : "No\n") << "\n";
    return 0;
}

