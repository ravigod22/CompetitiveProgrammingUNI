#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    i64 x, y;
    cin >> n >> m >> x >> y;
    map<i64, vector<i64>> dx;
    map<i64, vector<i64>> dy;
    for (int i = 0; i < n; ++i) {
        i64 u, v; cin >> u >> v;
        dx[u].emplace_back(v);
        dy[v].emplace_back(u);
    }
    map<i64, vector<pair<i64, i64>>> mpY;
    map<i64, vector<pair<i64, i64>>> mpX;
    vector<pair<char, i64>> dir;
    for (int i = 0; i < m; ++i) {
        char op; cin >> op;
        i64 c; cin >> c;
        i64 xt = x, yt = y;
        if (op == 'L') x -= c, mpY[yt].emplace_back(x, xt);
        if (op == 'U') y += c, mpX[xt].emplace_back(yt, y); 
        if (op == 'R') x += c, mpY[yt].emplace_back(xt, x);
        if (op == 'D') y -= c, mpX[xt].emplace_back(y, yt);
    }
    for (auto& [v, e] : mpY) sort(e.begin(), e.end());
    for (auto& [v, e] : mpX) sort(e.begin(), e.end());
    for (auto& [v, e] : dx) sort(e.begin(), e.end());
    for (auto& [v, e] : dy) sort(e.begin(), e.end());
    set<pair<i64, i64>> ans;
    for (auto& [v, e] : mpY) {
        vector<pair<i64, i64>> aux;
        for (auto& [l, r] : e) {
            if (aux.empty() || aux.back().second + 1 < l) {
                aux.emplace_back(l, r);
            }
            else if (aux.back().second < r) {
                aux.back().second = r;
            }
        }
        e = aux;
        int j = 0;
        vector<i64>& tmp = dy[v];
        for (auto &[l, r] : e) {
            while (j < (int)tmp.size() && tmp[j] <= r) {
                if (l <= tmp[j]) ans.emplace(tmp[j], v);
                ++j;
            }
        }
    }
    for (auto& [v, e] : mpX) {
        vector<pair<i64, i64>> aux;
        for (auto& [l, r] : e) {
            if (aux.empty() || aux.back().second + 1 < l) {
                aux.emplace_back(l, r);
            }
            else if (aux.back().second < r) {
                aux.back().second = r;
            }
        }
        e = aux;
        int j = 0;
        vector<i64> tmp = dx[v];
        for (auto& [l, r] : e) {
            while (j < (int)tmp.size() && tmp[j] <= r) {
                if (l <= tmp[j]) ans.emplace(v, tmp[j]);
                ++j;
            }
        }
    }
    cout << x << " " << y << " " << (int)ans.size() << "\n";
    return 0;
}

