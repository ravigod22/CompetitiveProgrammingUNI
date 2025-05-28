#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;



int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> lines(m);
    for (int i = 0; i < m; ++i)
        cin >> lines[i].first >> lines[i].second;
    sort(lines.begin(), lines.end(), [&](auto a, auto b) {
        return abs(a.first - a.second) < abs(b.first - b.second);
    });
    for (auto [l, r] : lines)
        cout << l << " " << r << "\n";
    return 0;
}
