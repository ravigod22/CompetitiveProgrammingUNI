#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

map<i64, i64> dp;

i64 f(i64 n) {
    if (n == 0) return 1;
    if (dp.count(n)) return dp[n];
    i64 &ans = dp[n] = 0;
    ans = f(n / 2) + f(n / 3);
    return ans;
}

int main() {
    i64 n; cin >> n;
    cout << f(n) << "\n";
    return 0;
}
