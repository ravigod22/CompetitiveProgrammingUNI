#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using pii = pair<int, int>;


int main() {
    int n; cin >> n;
    vector<pii> v(n);
    for (auto& e : v) cin >> e.first >> e.second;
    auto per = [&] (pii a, pii b, pii c, pii d) -> bool {
        return (a.y - c.y) * (b.y - d.y) == (c.x - a.x) * (b.x - d.x);
    };
    auto square = [&] (int x) -> int {
        return x * x;
    };
    auto dis = [&] (pii a, pii b) -> int {
        return square(a.x - b.x) + square(a.y - b.y);
    };
    auto validate = [&] (pii a, pii b, pii c, pii d) -> bool {
        set<pii> s;
        s.emplace(a), s.emplace(b), s.emplace(c), s.emplace(d);
        if (s.size() != 4) return 0;
        if (!per(a, b, c, d)) return 0;
        if (dis(a, b) != dis(c, d)) return 0;
        if (dis(a, d) != dis(b, c)) return 0;
        if (a.y != b.y || d.y != c.y) return 0;
        if (a.x != d.x || b.x != c.x) return 0;
        return 1;
    };
    
    auto inside = [&] (pii a, pii b, pii c, pii d, pii tmp) -> bool {
        if ((a.x <= tmp.x && tmp.x <= b.x) && (d.y <= tmp.y && tmp.y <= a.y)) return 1;
        if ((a.x <= tmp.x && tmp.x <= b.x) && (c.y <= tmp.y && tmp.y <= b.y)) return 1;
        if ((d.x <= tmp.x && tmp.x <= c.x) && (d.y <= tmp.y && tmp.y <= a.y)) return 1;
        if ((d.x <= tmp.x && tmp.y <= c.x) && (c.y <= tmp.y && tmp.y <= b.y)) return 1;
        return 0; 
    };
    auto area = [&] (pii a, pii b, pii c, pii d) -> int {
        return abs(a.x - b.x) * abs(a.y - d.y);
    };
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                for (int p = 0; p < n; ++p) {
                    if (validate(v[i], v[j], v[k], v[p])) {
                        bool vis[n];
                        memset(vis, 0, sizeof(vis));
                        vis[i] = vis[j] = vis[k] = vis[p] = 1;
                        int cnt = 0;
                        for (int q = 0; q < n; ++q) {
                            if (vis[q]) continue;
                            if (inside(v[i], v[j], v[k], v[p], v[q])) cnt++;
                        }
                        if (cnt == 0) ans = max(ans, area(v[i], v[j], v[k], v[p]));
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
