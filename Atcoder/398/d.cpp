#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, r, c; cin >> n >> r >> c;
    string s; cin >> s;
    string ans(n, '0');
    map<pair<int, int>, bool> vis;
    int x = 0, y = 0;
    vis[{0, 0}] = 1;
    for (int i = 0; i < n; ++i) {
        auto op = s[i];
        if (op == 'N') x++, r++;
        if (op == 'S') x--, r--;
        if (op == 'E') y--, c--;
        if (op == 'W') y++, c++;
        vis[{x, y}] = 1;
        if (vis.count({r, c})) ans[i] = '1';
    }
    cout << ans << "\n";
    return 0;
}



