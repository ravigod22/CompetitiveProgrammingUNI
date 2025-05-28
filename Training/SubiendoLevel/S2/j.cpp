#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n; cin >> n;
    map<i64, vector<i64>> mp;
    vector<i64> x(n);
    map<i64, int> cnt;
    for (auto& e : x) cin >> e, cnt[e]++;
    for (auto e : x) {
        for (int j = 0; j <= 30; ++j) {
            i64 tmp = 1LL << j;
            if (cnt.count(e + tmp)) mp[e].push_back(e + tmp);
            if (cnt.count(e - tmp)) mp[e].push_back(e - tmp);
        }
    }
    int ans = 0;
    vector<int> last, sol, cycle;
    for (auto e : x) {
        if (mp[e].empty() && last.empty()) {
            last.emplace_back(e);
            ans = 1;
        }
        else if (mp[e].size() >= 1 && sol.empty()) {
            ans = max(ans, 2);
            sol.emplace_back(e);
            sol.emplace_back(mp[e].front());
        }
        bool find_cycle = false;
        // current -> neighboord
        for (auto neigh : mp[e]) {
            for (auto neigh_to_neigh : mp[neigh]) {
                bool find_element = false;
                for (auto element : mp[neigh_to_neigh]) {
                    if (element == e) find_element = true;
                }
                if (find_element) {
                    cycle.push_back(e);
                    cycle.push_back(neigh);
                    cycle.push_back(neigh_to_neigh);
                    find_cycle = true;
                    ans = 3;
                    break;
                }
            }
            if (find_cycle) break;
        }
        if (find_cycle) break;
    }
    cout << ans << "\n";
    if (ans == 3) {
        for (int e : cycle) cout << e << " ";
    }
    else if (ans == 2) {
        for (int e : sol) cout << e << " ";
    }
    else if (ans == 1) {
        cout << last[0];
    }
    cout << "\n";
    return 0;
}
