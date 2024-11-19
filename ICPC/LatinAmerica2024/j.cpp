#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)


int main() {
    int the, n; cin >> the >> n;
    vector<pair<double, double>> shadow;
    double ang = pi * the / 180;
    for (int i = 0; i < n; ++i) {
        int x, h; cin >> x >> h;
        double y = h * cos(ang) / sin(ang);
        shadow.emplace_back(x, x + y);
    }
    sort(shadow.begin(), shadow.end());
    pair<double, double> cur = shadow[0];
    double dis = 0;
    for (int i = 1; i < n; ++i) {
        if (shadow[i].first < cur.second) {
            cur.second = max(cur.second, shadow[i].second);
        }
        else {
            dis += cur.second - cur.first;
            cur = shadow[i];
        }
    }
    dis += cur.second - cur.first;
    cout << fixed << setprecision(10) << dis << "\n";
    return 0;
}
