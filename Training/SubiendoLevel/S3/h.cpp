#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 inf = 1e18;

int main() {
    int n, W; cin >> n >> W;
    vector<int> v(n), w(n), m(n);
    for (int i = 0; i < n; ++i) cin >> v[i] >> w[i] >> m[i];
    vector<i64> dp(W + 1, -inf);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        vector<i64> newdp = dp; 
        for (int j = 0; j < w[i]; ++j) {
            deque<pair<i64, int>> states;
            for (int k = j, cnt = 0; k <= W; k += w[i], cnt++) {
                while (!states.empty() && states.front().second < cnt - m[i]) states.pop_front();
                if (!states.empty()) newdp[k] = max(newdp[k], states.front().first + 1LL * v[i] * (cnt - states.front().second));
                while (!states.empty() && states.back().first + 1LL * v[i] * (cnt - states.back().second) < dp[k]) {
                    states.pop_back();
                }
                states.emplace_back(dp[k], cnt);
            }
        }
        swap(dp, newdp);
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
    return 0;
}
