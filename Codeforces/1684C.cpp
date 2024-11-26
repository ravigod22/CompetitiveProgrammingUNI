#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> a(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x; cin >> x;
            a[i].emplace_back(x, j + 1);
        }
    }
    int in = -1, im = -1;
    for (int i = 0; i < n; ++i) {
        vector<pair<int, int>> tmp = a[i];
        map<int, int> last;
        sort(tmp.begin(), tmp.end());
        int cnt = 0;
        for (int j = 0; j < m; ++j) {
            last[tmp[j].first] = max(last[tmp[j].first], tmp[j].second); 
            if (a[i][j].first != tmp[j].first) cnt++;
        }
        if (cnt > 2) {
            cout << -1 << "\n";
            return;
        }
        if (cnt == 2) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j].first != tmp[j].first) {
                    in = a[i][j].second;
                    im = last[tmp[j].first];
                    break;
                }
            }
            break;
        }
    }
    if (in == -1 && im == -1) in = 1, im = 1;
    for (int i = 0; i < n; ++i) {
        swap(a[i][in - 1], a[i][im - 1]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (a[i][j - 1].first > a[i][j].first) {
                cout << -1 << "\n";
                return;
            }
        }
    }
    cout << in << " " << im << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
