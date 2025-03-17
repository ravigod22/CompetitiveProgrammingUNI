#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int& e : a) cin >> e;
        for (int& e : b) cin >> e;
        vector<int> resA(2 * n + 1, 0);
        vector<int> resB(2 * n + 1, 0);
        for (int i = 0; i < n; ) {
            int aux = 0;
            int cur = a[i];
            while (i < n && cur == a[i]) aux++, i++;
            resA[cur] = max(resA[cur], aux);
        }
        for (int i = 0; i < n; ) {
            int aux = 0;
            int cur = b[i];
            while (i < n && cur == b[i]) aux++, ++i;
            resB[cur] = max(resB[cur], aux);
        }
        int ans = 0;
        for (int i = 1; i <= 2 * n; ++i) {
            ans = max(ans, resA[i] + resB[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}
