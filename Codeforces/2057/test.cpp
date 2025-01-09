#include <bits/stdc++.h>
using namespace std;

int main() {
    int l, r; cin >> l >> r;
    map<int, vector<tuple<int, int, int>>> mp;
    auto f = [&] (int x1, int x2, int x3) -> int {
        return (x1 ^ x2) + (x1 ^ x3) + (x2 ^ x3);
    };
    for (int i = l; i <= r; ++i) {
        for (int j = l; j <= r; ++j) {
            for (int k = l; k <= r; ++k) {
                mp[f(i, j, k)].emplace_back(i, j, k);
            }
        }
    }
    for (auto e : mp) {
        cout << e.first << "\n";
        for (auto [x, y, z] : e.second) cout << x << " " << y << " " << z << "\n";
    }
    return 0;
}
