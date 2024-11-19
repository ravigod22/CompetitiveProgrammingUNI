#include <bits/stdc++.h>
using namespace std;

int square(int x) {
    return x * x;
}
int dis(int x0, int y0, int x1, int y1) {
    return square(x0 - x1) + square(y0 - y1);
}
int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> points;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }
    for (int i = 0; i < n; ++i) {
        int dis_max = 0;
        int ind_points = 2e9;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            dis_max = max(dis_max, dis(points[i].first, points[i].second, points[j].first, points[j].second));
        }
        cout << dis_max << "\n";
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (dis(points[i].first, points[i].second, points[j].first, points[j].second == dis_max)) {
                ind_points = min(ind_points, j);
            }
        }
        cout << ind_points << "\n";
    }
    return 0;
}
