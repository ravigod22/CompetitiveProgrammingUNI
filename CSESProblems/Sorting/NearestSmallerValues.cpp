#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    map<int, vector<int>> mp;
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    set<int> id;
    for (auto [v, k] : mp) {
        for (int e : k) {
            auto it = id.lower_bound(e);
            if (it == id.begin()) ans[e] = -1;
            else {
                int pos = *prev(it);
                ans[e] = pos;
            }
        }
        for (int e : k) {
            id.insert(e);
        }
    }
    for (int i = 0; i < n; ++i) cout << ans[i] + 1 << " \n"[i + 1 == n];
    return 0;
}
