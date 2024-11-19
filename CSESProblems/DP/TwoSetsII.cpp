#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main() {
	int n; cin >> n;
	int sum = n * (n + 1) / 2;
	if (sum & 1) {
		cout << 0;
		return 0;
	}
	sum /= 2;
	int dp[n][sum + 1];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
    for (int i = 1; i < n; ++i) {
		for (int j = 0; j <= sum; ++j) {
		    dp[i][j] = dp[i - 1][j];
            if (j >= i) dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % mod;
        }
	}
    cout << dp[n - 1][sum] << "\n";
	return 0;
}
