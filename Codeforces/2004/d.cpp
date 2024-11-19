#include <bits/stdc++.h>
using namespace std;
const string tmp[6] = {"BG", "BR", "BY", "GR", "GY", "RY"};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, q; cin >> n >> q;
        set<int> poss[6];
        vector<string> s(n);
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            for (int j = 0; j < 6; ++j) {
                if (s[i] == tmp[j]) poss[j].emplace(i + 1);
            }
        }
        for (int i = 0; i < q; ++i) {
            int u, v; cin >> u >> v;
            set<char> tmp1;
            for (auto e : s[u - 1]) tmp1.emplace(e);
            for (auto e : s[v - 1]) tmp1.emplace(e);
            if (tmp1.size() == 4) {
                int ans = 1e9;
                for (int j = 0; j < 6; ++j) {
                    if (tmp[j] != s[u - 1] && tmp[j] != s[v - 1]) {
                        poss[j].insert(u);
                        auto ind = poss[j].find(u);
                        if (ind != poss[j].begin()) {
                            auto ind2 = prev(ind);
                            ans = min(ans, abs(*ind2 - u) + abs(*ind2 - v));
                        }
                        if (next(ind) != poss[j].end()) {
                            auto ind2 = next(ind);
                            ans = min(ans, abs(*ind2 - u) + abs(*ind2 - v));
                        }
                        poss[j].erase(u);
                    }
                } 
                if (ans == 1e9) ans = -1;
                cout << ans << "\n";
            }
            else if (tmp1.size() <= 3) {
                cout << abs(u - v) << "\n";
            }
            tmp1.clear();
        }
    }
    return 0;
}

