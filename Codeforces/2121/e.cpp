#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl
const int N = 20;
const int inf = 1e3;
int l, r;
string L, R;
int dp[N][2][2];
int n;

int f(int pos, bool sameL, bool sameR) {
    if (pos == n) return 0;
    if (~dp[pos][sameL][sameR]) return dp[pos][sameL][sameR];
    int &ans = dp[pos][sameL][sameR] = inf;
    if (sameL && !sameR) {
        for (int i = L[pos] - '0'; i < 10; ++i) {
            char tmp = '0' + i;
            ans = min(ans, (tmp == L[pos]) + (tmp == R[pos]) + f(pos + 1, (tmp == L[pos]), (tmp == R[pos])));
        }
    }
    else if (!sameL && sameR) {
        for (int i = 0; i <= R[pos] - '0'; ++i) {
            char tmp = '0' + i;
            ans = min(ans, (tmp == L[pos]) + (tmp == R[pos]) + f(pos + 1, (tmp == L[pos]), (tmp == R[pos])));
        }
    }
    else if (sameL && sameR) {
        for (int i = L[pos] - '0'; i <= R[pos] - '0'; ++i) {
            char tmp = '0' + i;
            ans = min(ans, (tmp == L[pos]) + (tmp == R[pos]) + f(pos + 1, (tmp == L[pos]), (tmp == R[pos])));
        }
    }
    else {
        for (int i = 0; i < 10; ++i) {
            char tmp = '0' + i;
            ans = min(ans, (tmp == L[pos]) + (tmp == R[pos]) + f(pos + 1, (tmp == L[pos]), (tmp == R[pos])));
        }
    }
    return ans;
}


void solve() {
    cin >> l >> r;
    L = to_string(l);
    R = to_string(r);
    n = L.size();
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                dp[i][j][k] = -1;
    cout << f(0, 1, 1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


