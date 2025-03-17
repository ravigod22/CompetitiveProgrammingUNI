#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        int m; cin >> m;
        vector<int> cnt(30, 0);
        while (m--) {
            int op; cin >> op;
            if (op == 1) {
                int x; cin >> x;
                cnt[x]++;
            }
            else {
                int w; cin >> w;
                int sum = 0;
                bool can = true;
                for (int i = 0; i < 30; ++i) {
                    int bit = (w >> i) & 1;
                    if (bit) {
                        if (sum + cnt[i] >= 1) sum--;   
                        else {
                            can = false;
                            break;
                        }
                    }
                    sum += cnt[i];
                    sum /= 2;
                }
                cout << (can ? "YES\n" : "NO\n");
            }
        }
    }
    return 0;
}
