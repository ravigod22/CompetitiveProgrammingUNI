#include <bits/stdc++.h>
using namespace std;

int h, w, d;
char g[15][15];

int main() {
    cin >> h >> w >> d;
    vector<pair<int, int>> tmp;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            cin >> g[i][j];
            if (g[i][j] == '.') {
                tmp.emplace_back(i, j);
            }
        }
    }
    auto manh = [&] (pair<int, int> p1, pair<int, int> p2) -> int {
        return abs(p1.first - p2.first) + abs(p1.second - p2.second);
    };

    auto check = [&] (pair<int, int> p1, pair<int, int> p2) -> int {
        int cnt = 0;
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                if (g[i][j] != '.') continue;
                pair<int, int> aux = {i, j};
                if (manh(p1, aux) <= d or manh(p2, aux) <= d) cnt++; 
            }
        }
        return cnt;
    };
    int ans = 0;
    for (auto e1 : tmp) {
        for (auto e2 : tmp) {
            ans = max(ans, check(e1, e2));
        }
    }
    cout << ans << "\n";
    return 0;
}

