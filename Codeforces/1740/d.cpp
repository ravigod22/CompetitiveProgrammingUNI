#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m, k; cin >> n >> m >> k;
        vector<int> card(k);
        for (int& e : card) cin >> e;
        set<int> hold;
        int p = k;
        int lim = n * m - 4;
        bool can = true;
        for (int i = 0; i < k; ++i) {
            int cur = card[i];
            if (cur == p) {
                if ((int)hold.size() <= lim) p--;
                else {
                    can = false;
                    break;
                }
            }
            else {
                while (!hold.empty() && (*hold.rbegin()) == p) {
                    hold.erase(--hold.end());
                    p--;
                }
                hold.emplace(card[i]);
                if ((int)hold.size() > lim) {
                    can = false;
                    break;
                }
            }
        }
        cout << (can ? "YA" : "TIDAK") << "\n";
    }
    return 0;
}
