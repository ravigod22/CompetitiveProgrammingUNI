#include <bits/stdc++.h>
using namespace std;


int compare(vector<vector<char>> a, vector<vector<char>> b) {
    int cnt = 0;
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a[0].size(); ++j) {
            cnt += (a[i][j] != b[i][j]);
        }
    }
    return cnt;
}

void rotate(vector<vector<char>> &a) {
    const int n = a.size(), m = a[0].size();
    vector<vector<char>> ans(n, vector<char> (m));
    // transpose
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans[i][j] = a[j][i];
        }
    }
    for (int j = 0; j < m / 2; ++j) {
        for (int i = 0; i < n; ++i) {
            swap(ans[i][j], ans[i][m - j - 1]);
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            a[i][j] = ans[i][j];
}

int main() {
    int n; cin >> n;
    vector<vector<char>> s(n, vector<char> (n));
    vector<vector<char>> t(n, vector<char> (n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> s[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> t[i][j];
    int ans = 1e9;
    for (int i = 0; i < 4; ++i) {
        vector<vector<char>> tmp = s;
        ans = min(ans, i + compare(tmp, t));
        rotate(s);
    }
    cout << ans << "\n";
    return 0;
}
