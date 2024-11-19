#include <bits/stdc++.h>
using namespace std;

double square(int x) {
    return (long double) (1ll * x * x);
}
double dis(int x1, int y1, int x2, int y2) {
    return sqrtl(square(x1 - x2) + square(y1 - y2)); 
}

bool f(double mid, vector<int> &light, vector<pair<int,int>> &pos) {
    int n = pos.size();
    int k = light.size();
    vector<bool> vis(n, false);
    for (int i = 0; i < k; ++i) {
        auto x = pos[light[i] - 1];
        vis[light[i] - 1] = true;
        for (int j = 0; j < n; ++j) {
            auto y = pos[j];
            if (x == y) continue;
            if (vis[j]) continue;
            if (dis(x.first, x.second, y.first, y.second) < mid) vis[j] = true;
        }
    }
    for (int i = 0; i < n; ++i) if (!vis[i]) return 0;
    return 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(9);
    int tt = 1;
    //cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> light(k);
        for (int i = 0; i < k; ++i) cin >> light[i];
        vector<pair<int, int>> pos(n);
        for (int i = 0; i < n; ++i) cin >> pos[i].first >> pos[i].second;
        double lo = 0;
        double hi = 2e9;
        int ite = 90;
        while (ite--) {
            double mid = (lo + hi) / 2;
            if (f(mid, light, pos)) hi = mid;
            else lo = mid;
            //cout << lo << " " << hi << "\n";
        }
        cout << lo << "\n";
    }
    return 0;
}
