#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    vector<int> dp(n + 1, inf);
    vector<int> last(n + 1, -1);
    vector<int> parent(n, -1);
    dp[0] = -inf;
    for (int i = 0; i < n; ++i) {
        int ind = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        if (dp[ind - 1] < a[i] && a[i] < dp[ind]) {
            dp[ind] = a[i];
            last[ind] = i;
            parent[i] = last[ind - 1];
        }
    }
    int result = 0;
    int pos = 0;
    for (int i = 1; i <= n; ++i) {
        if (dp[i] < inf) {
            result = i;
            pos = last[i];
        }
    }
    // build the optimal path
    vector<int> build;
    while (pos != -1) {
        build.emplace_back(a[pos]);
        pos = parent[pos];
    }
    reverse(build.begin(), build.end());
    cout << result << "\n";
    return 0;
}
