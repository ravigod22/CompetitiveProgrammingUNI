#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int maxn = 2e5 + 5;
vector<int> square(maxn, -1);

void init() {
    for (int i = 1; i * i <= 2e5; ++i) {
        square[i * i] = i;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto& e : a) cin >> e;
        vector<pair<int, int>> divi[n];
        for (int i = 0; i < n; ++i) {
            int cur = a[i];
            vector<pair<int, int>> aux;
            for (int j = 2; j * j <= cur; ++j) {
                if (cur % j == 0) {
                    int cnt = 0;
                    while (cur % j == 0) {
                        cnt++, cur /= j;
                    }
                    aux.emplace_back(j, cnt);
                }
            }
            if (cur > 1) aux.emplace_back(cur, 1);
            if (aux.size() <= 2) {
                if (aux.size() == 1) {
                    auto [prime, cnt] = aux.back();
                    if (cnt <= 2) divi[i] = aux;
                }
                else if (aux.size() == 2) {
                    if (aux[0].second == 1 && aux[1].second == 1) divi[i] = aux;
                }
            }
        }
        vector<int> mul(n + 1, 0);
        vector<int> cnt(n + 1, 0);
        int cntprimes = 0;
        i64 ans = 0;
        for (int i = 0; i < n; ++i) {
            if (divi[i].empty()) continue;
            cnt[a[i]]++;
            if (square[a[i]] == -1) {
                if (divi[i].size() == 1) {
                    auto [p, _] = divi[i].front();
                    cntprimes++;
                    ans += cntprimes - cnt[p];
                    ans += mul[p];
                }
                else if (divi[i].size() == 2) {
                    auto [p1, cnt1] = divi[i].front();
                    auto [p2, cnt2] = divi[i].back();
                    mul[p1]++;
                    mul[p2]++;
                    ans += cnt[p1];
                    ans += cnt[p2];
                    ans += cnt[p1 * p2];
                }
            }
            else {
                mul[square[a[i]]]++;
                ans += cnt[a[i]];
                ans += cnt[square[a[i]]];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
