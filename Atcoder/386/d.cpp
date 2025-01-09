#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<array<int, 3>> mp;
    for (int i = 0; i < m; ++i) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        if (c == 'W') mp.push_back({x, y, 1});
        else mp.push_back({x, y, 0});
    }
    sort(mp.begin(), mp.end());
    int can = 1e9;
    for (auto& [x, y, c] : mp) {
        if (c == 1) can = min(can, y);
        else {
            if (can <= y) {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
    return 0;
}
