#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m, k; cin >> n >> m >> k;
        vector<int> a(m);
        for (int& e : a) cin >> e;
        sort(a.rbegin(), a.rend());
        int tmp = n % k;
        int maxc = (n / k) + 1;
        bool could = true;
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            if (a[i] > maxc) could = false;
            if (a[i] == maxc) cnt++;
        }
        cout << (cnt <= tmp && could ? "YES\n" : "NO\n");
    }
    return 0;
}
