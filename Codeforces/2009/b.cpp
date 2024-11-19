#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 5;
char grid[maxn][maxn];
int n;

void solve() {
    cin >> n;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (grid[i][j] == '#') ans.emplace_back(j + 1);
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " \n"[i + 1 == ans.size()];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

