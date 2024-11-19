#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int,set<int>> beans;
    for (int i = 0; i < n; ++i) {
        int a, c;
        cin >> a >> c;
        beans[c].emplace(a);
    }
    int ans = 0;
    for (auto e : beans) {
        ans = max(ans, *beans[e.first].begin());
    }
    cout << ans << "\n";
    return 0;
}
