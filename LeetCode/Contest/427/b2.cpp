#include <bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
using namespace std;
using pii = pair<int, int>;


int main() {
    int n; cin >> n;
    vector<pii> v(n);
    for (auto& e : v) cin >> e.first >> e.second;
    sort(v.begin(), v.end());
    vector<vector<int>> tmp;
    vector<int> x;
    for (int i = 0; i < n; ) {
        int aux = v[i].first;
        vector<int> index;
        while (i < n && aux == v[i].first) {
            index.emplace_back(v[i].second);
            ++i;
        }
        tmp.emplace_back(index);
        x.emplace_back(aux);
    }

    int ans = -1;
    for (int i = 0; i + 1 < tmp.size(); ++i) {
        for (int j = i + 1; j < tmp.size(); ++j) {
            for (int p = 1; p < tmp[i].size(); ++p) {
                for (int q = 1; q < tmp[j].size(); ++q) {
                    if (tmp[i][p - 1] == tmp[j][q - 1] && tmp[i][p] == tmp[j][q]) {
                        for (int k = 0; k < n; ++k) {
                            if (v[k] == mp(x[i], tmp[i][p - 1])) continue;
                            if (v[k] == mp(x[i], tmp[i][p])) continue;
                            if (v[k] == mp(x[j], tmp[j][q])) continue;
                            if (v[k] == mp(x[j], tmp[j][q - 1])) continue;
                            int cnt = 0;
                            if (tmp[i][p - 1] <= v[k].second && v[k].second <= tmp[i][p]) cnt++;
                            if (x[i] <= v[k].first && v[k].first <= x[j]) cnt++;
                            if (cnt != 2) ans = max(ans, (x[j] - x[i]) * (tmp[i][p] - tmp[i][p - 1]));
                        }
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

