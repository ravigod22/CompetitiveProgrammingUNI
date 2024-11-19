#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000 + 10;
int n;
int a[maxn];
long long prefix[maxn];
long long dp[maxn][maxn];
int pos[maxn];
int tmp = 1;
string result;


int f(int l, int r) {
    if (l == r) return a[l];
    if (~dp[l][r]) return dp[l][r];
    long long& x = dp[l][r];
    x = prefix[r] - prefix[l - 1] + max(f(l + 1, r), f(l, r - 1));
    return x;
}

void build(int l, int r) {
    if (l == r) {
        pos[l] = tmp;
        result += "L";
        return;
    }
    if (f(l + 1, r) > f(l, r - 1)) {
        result += "L";
        pos[l] = tmp++;
        build(l + 1, r);
    } 
    else {
        result += "R";
        pos[r] = tmp++;
        build(l, r - 1);
    }
}
int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        prefix[i] = 0ll + a[i] + prefix[i - 1];
    }
    build(1, n);
    cout << "the result " << f(1, n) << "\n";
    cout << "the path " << result << "\n";
    cout << "positions\n";
    for (int i = 1; i <= n; ++i) cout << pos[i] << " \n"[i == n];
    return 0;
}
