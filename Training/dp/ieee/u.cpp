#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
const int maxk = 1e5 + 5;
int n, k;
int choose[maxn];
int dp[2][maxk];

int play(int jugador, int remain) {
    if (remain <= 0) return (remain == 0 ? false : true);
    if (~dp[jugador][remain]) return dp[jugador][remain];
    int &res = dp[jugador][remain] = 0;
    for (int i = 0; i < n; ++i) {
        if (play(jugador ^ 1, remain - choose[i]) == 0) res = 1;
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> choose[i];
    if (play(0, k)) cout << "First" << "\n";
    else cout << "Second" << "\n";
    return 0;
}
