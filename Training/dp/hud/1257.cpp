#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int LIS_min(vector<int>& h) {
    int m = h.size();
    const int inf = 1e9;
    vector<int> dp(m + 1, inf);
    dp[0] = -inf;
    for (int i = 0; i < m; ++i) {
        int ind = upper_bound(dp.begin(), dp.end(), h[i]) - dp.begin();
        if (dp[ind - 1] < h[i] && h[i] < dp[ind]) {
            dp[ind] = h[i];
        }
    }
    int result = 1;
    for (int i = 1; i <= m; ++i) {
        if (dp[i] < inf) result = i;
    }    
    return result;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> h(n);
        for (int i = 0; i < n; ++i) cin >> h[i];
        cout << LIS_min(h) << "\n";
    }
    return 0;
}
