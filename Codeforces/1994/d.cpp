#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> pos[n][n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            for (int j = 1; j < n; ++j) {
                pos[j][a[i] % j].emplace_back(i);
            }
        }
        if (n == 1) {
            cout << "YES\n";
            continue;
        }
        vector<int> color(n);
        iota(color.begin(), color.end(), 0);
        vector<int> same[n];
        for (int i = 0; i < n; ++i) same[i].emplace_back(i);
        vector<pair<int, int>> result;
        for (int i = n - 1; i > 0; --i) {
            int u, v;
            for (int j = 0; j < i; ++j) {
                if (pos[i][j].size() < 2) continue;
                vector<int> tmp = pos[i][j];
                auto join = [&] (int a, int b) -> void {
                    if (same[a].size() < same[b].size()) {
                        for (auto& e : same[a]) {
                            same[b].emplace_back(e);
                            color[e] = b;
                        }
                        while (!same[a].empty()) same[a].pop_back();
                    }
                    else {
                        for (auto& e : same[b]) {
                            same[a].emplace_back(e);
                            color[e] = a;
                        }
                        while (!same[b].empty()) same[b].pop_back();
                    }
                };
                bool can = false;
                for (int k = 1; k < tmp.size(); ++k) {
                    if (color[tmp[0]] != color[tmp[k]]) {
                        join(color[tmp[0]], color[tmp[k]]);
                        u = tmp[0];
                        v = tmp[k];
                        can = true;
                        break;
                    }
                }
                if (can) break;
            }
            result.emplace_back(u + 1, v + 1);
        }
        reverse(result.begin(), result.end());
        cout << "YES\n";
        for (auto& e : result) {
            cout << e.first << " " << e.second << "\n";
        }
    }
    return 0;
}
