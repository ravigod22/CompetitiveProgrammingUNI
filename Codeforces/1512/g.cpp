#include <bits/stdc++.h>
using namespace std;
const int mxc = 1e7;
const int inf = 2e9;
int lp[mxc + 1];
int dp[mxc + 1];
long long sumdiv[mxc + 1];
vector<int> pr;

void sieve() {
    for (int i = 2; i <= mxc; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; 1LL * i * pr[j] <= mxc; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) break;
        }
    }
    sumdiv[1] = 1;
    dp[1] = 1;
    for (int i = 2; i <= mxc; ++i) {
        int aux = 1;
        int tmp = i;
        while (tmp % lp[i] == 0) {
            tmp /= lp[i];
            aux = (aux * lp[i]) + 1;
        }
        sumdiv[i] = 1LL * aux * sumdiv[tmp];
        if (sumdiv[i] <= mxc && !dp[sumdiv[i]]) dp[sumdiv[i]] = i;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    int tt; cin >> tt;
    while (tt--) {
        int c; cin >> c;
        cout << (dp[c] ? dp[c] : -1) << "\n";
    }
    return 0;
}
