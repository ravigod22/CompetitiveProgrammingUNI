#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    vector<pair<int,int>> c;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        c.emplace_back(x, 1);
    }
    for (int i = 0; i < m; ++i) {
        int x; cin >> x;
        c.emplace_back(x, 2);
    }
    sort(c.begin(), c.end());
    bool could = false;
    for (int i = 1; i < n + m; ++i) {
        if (c[i].second == 1 && c[i - 1].second == 1) could = true;
    }
    cout << (could ? "Yes\n" : "No\n");
    return 0;
}

