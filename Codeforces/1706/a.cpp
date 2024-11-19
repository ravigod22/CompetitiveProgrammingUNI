#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<int> cnt(m + 1, 0);
        vector<int> a(n);
        string ans(m, 'B');
        for (int& e : a) {
            cin >> e;
            cnt[e]++;
        }
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        for (int i = 0; i < a.size(); ++i) {
            if (cnt[a[i]] > 1) {
                ans[a[i] - 1] = 'A';
                ans[m - a[i]] = 'A';
            }
            else {
                int tmp = min(a[i] - 1, m - a[i]);
                if (ans[tmp] == 'A') ans[max(a[i] - 1, m - a[i])] = 'A'; 
                else ans[tmp] = 'A';
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
