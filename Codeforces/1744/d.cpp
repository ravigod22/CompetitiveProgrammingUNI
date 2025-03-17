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
        for (int& e : a) cin >> e;
        int cnt2 = 0;
        vector<int> can;
        for (int i = 0; i < n; ++i) {
            int tmp = a[i];
            while (tmp % 2 == 0) {
                tmp /= 2;
                cnt2++;
            }
        }
        for (int i = 1; i <= n; ++i) {
            int tmp = i;
            int aux = 0;
            while (tmp % 2 == 0) {
                tmp /= 2;
                aux++;
            }
            if (aux) can.emplace_back(aux);
        }
        sort(can.rbegin(), can.rend());
        int ans = 0;
        for (int i = 0; i < (int)can.size(); ++i) {
            if (cnt2 < n) {
                cnt2 += can[i];
                ans++;
            }
            else break;
        }
        if (cnt2 < n) ans = -1;
        cout << ans << "\n";
    }
    return 0;
}

