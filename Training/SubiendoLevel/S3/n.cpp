#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int n;
int x[maxn], y[maxn];
bool vis[maxn][maxn];
pair<int, pair<int, int>> dp[maxn][maxn];


pair<int, pair<int, int>> f(int l, int r) {
    if (l == r) return make_pair(0, make_pair(x[l], y[l]));
    if (vis[l][r]) return dp[l][r];
    vis[l][r] = true;
    auto& aux = dp[l][r];
    aux.second.first = x[l];
    aux.second.second = y[l];
    aux.first = 1e9;
    for (int i = l; i < r; ++i) {
        int sum = x[l] * y[r] * y[i];
        sum += f(l, i).first + f(i + 1, r).first;
        // (l, i) * (i + 1, r)
        aux.first = min(aux.first, sum);
    }
    return aux;
}

string build(int l, int r) {
    if (l == r) {
        return "A" + to_string(l);
    }
    string ans;
    for (int i = l; i < r; ++i) {
        int sum = x[l] * y[r] * y[i];
        sum += f(l, i).first + f(i + 1, r).first;
        if (f(l, r).first == sum) {
            ans = "(" + build(l, i) + " x " + build(i + 1, r) + ")";
            break;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (true) {
        cin >> n;
        if (!n) break;
        for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                vis[i][j] = false;
            }
        }
        string res = build(1, n);
        cout << "Case " << t++ << ": " << res << "\n";
    }
    return 0;
}
