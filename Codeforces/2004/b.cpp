#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        vector<pair<int, int>> pos(2);    
        for (int i = 0; i < 2; ++i) cin >> pos[i].first >> pos[i].second;
        sort(pos.begin(), pos.end());
        //for (auto e : pos) cout << e.first << " " << e.second << "\n";
        //cout << "\n";
        int ans = 0;
        if (pos[1].first > pos[0].second) ans = 1;
        else {
            int b[4] = {pos[1].first, pos[1].second, pos[0].first, pos[0].second};
            sort(b, b + 4);
            ans = (b[1] - b[0] > 0 ? 1 : 0) + b[2] - b[1] + (b[3] - b[2] > 0 ? 1 : 0);
        }
        cout << ans << "\n";
    }
    return 0;
}

