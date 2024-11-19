#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 1e9 + 7;

int main() {
    int n = 90;
    int64_t dp[101];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < 100; ++i) {
        dp[i] = (0ll + dp[i - 1] + dp[i - 2]) % mod;
    } 
    int64_t prefix[102];
    prefix[0] = 0;
    for (int i = 1; i < 100; ++i) {
        prefix[i] = (dp[i] + prefix[i - 1]) % mod; 
    }
    if (dp[n + 2] - 1 == prefix[n]) cout << "Verificate";
    else cout << "error";
    return 0;
}
