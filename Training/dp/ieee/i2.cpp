#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 inf = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, W; cin >> n >> W;
    vector<int> weight(n), value(n), times(n);
    for (int i = 0; i < n; ++i) {
        cin >> value[i] >> weight[i] >> times[i];
    }
    vector<i64> dp(W + 1, -inf);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        vector<i64> newdp(W + 1, 0);
        for (int j = 0; j < weight[i]; ++j) {
            deque<pair<i64, int>> states;
            for (int k = j, cnt = 0; k <= W; k += weight[i], cnt++) {
                while (!states.empty() && states.back().first + 1LL * value[i] * (cnt - states.back().second) < dp[k]) {
                    states.pop_back();
                }
                states.emplace_back(dp[k], cnt);
                newdp[k] = states.front().first + 1LL * value[i] * (cnt - states.front().second);
                while (!states.empty() && states.front().first <= cnt - times[i]) {
                    states.pop_front();
                }
            } 
        }
        swap(newdp, dp);
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
    return 0;
}

