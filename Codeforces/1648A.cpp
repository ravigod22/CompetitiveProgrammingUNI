#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int main() {
    int n, m;
    cin >> n >> m;
    int c[n][m];
    vector<pair<int,int>> G[maxn];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> c[i][j];
            G[c[i][j]].emplace_back(i, j);
        }
    }
    long long result = 0;
    for (int i = 1; i <= maxn; ++i) {
        if (G[i].empty()) continue;
        int k = G[i].size();
        long long sum = 0;
        if (k == 1) {
            sum = 0;
        }
        else {
            vector<pair<int,int>> tmp = G[i];
            vector<int> x, y;
            for (int i = 0; i < k; ++i) {
                x.emplace_back(tmp[i].first);
                y.emplace_back(tmp[i].second);
            }
            sort(x.begin(), x.end());
            sort(y.begin(), y.end());
            vector<long long> prefix_x(k, 0);
            vector<long long> prefix_y(k, 0);
            for (int i = 0; i < k; ++i) {
                prefix_x[i] = (i ? prefix_x[i - 1] : 0) + 1ll * x[i];
                prefix_y[i] = (i ? prefix_y[i - 1] : 0) + 1ll * y[i];
            }
            for (int i = 0; i < k; ++i) {
                sum += (prefix_x[k - 1] - (i ? prefix_x[i - 1] : 0)) - (1ll * (k - i) * x[i]);
                sum += (prefix_y[k - 1] - (i ? prefix_y[i - 1] : 0)) - (1ll * (k - i) * y[i]);
            }
            x.clear();
            y.clear();
        }
        result += sum;
    }
    cout << result << "\n";
    return 0;
}
