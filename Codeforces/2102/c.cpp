#include <bits/stdc++.h>
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int a = (n - 1) / 2, b = (n - 1) / 2;
        int p = 1, q = 0;
        int ans[n][n];
        ans[a][b] = 0;
        vector<int> step;
        for (int i = 0; i < n; ++i) {
            step.push_back(i + 1);
            step.push_back(i + 1);
        }
        for (int i = 0; i < step.size() && p < n * n; ++i) {
            for (int j = 0; j < step[i] && p < n * n; ++j) {
                int ind = i % 4;
                a += dx[ind];
                b += dy[ind];
                ans[a][b] = p++;
            }
        }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cout << ans[i][j] << " \n"[j + 1 == n];
    }
    return 0;
}
