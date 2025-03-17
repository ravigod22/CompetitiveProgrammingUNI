#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
    int n; cin >> n;
    vector<vector<int>> ndice(n, vector<int> (1e5 + 2, 0));
    vector<int> siz;
    set<int> cnt[n];
    for (int i = 0; i < n; ++i) {
        int k; cin >> k;
        siz.emplace_back(k);
        for (int j = 0; j < k; ++j) {
            int x; cin >> x;
            cnt[i].emplace(x);
            ndice[i][x]++;
        }
    }
    long double ans = 0.0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            set<int> space;
            if (cnt[i].size() < cnt[j].size()) {
                for (auto e : cnt[i]) {
                    if (cnt[j].count(e)) space.emplace(e);
                }
            }
            else {
                for (auto e : cnt[j]) {
                    if (cnt[i].count(e)) space.emplace(e);
                }
            }
            long double tmp = 0;
            for (int e : space) {
                long double f = 1.0 * ndice[i][e] / siz[i];
                long double s = 1.0 * ndice[j][e] / siz[j];
                tmp += 1.0 * f * s;
            }
            ans = max(ans, tmp);
        }
    }
    cout << ans << "\n";
    return 0;
}



