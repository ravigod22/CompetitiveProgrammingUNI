#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        map<int, int> cnt;
        for (int& e : a) cin >> e, cnt[e]++;
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        int ans = 0;
        for (int i = 0; i < (int)a.size(); ) {
            int cur = a[i];
            int maxe = 0;
            while (i < (int)a.size() && cur == a[i]) {
                maxe = max(maxe, cnt[cur]);
                cur++, i++;
            }
            ans += maxe;
        }
        cout << ans << "\n";
    }
    return 0;
}
