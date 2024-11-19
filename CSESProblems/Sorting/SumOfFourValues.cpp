#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, x; cin >> n >> x;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; ++i) {
        int p; cin >> p;
        a.emplace_back(p, i + 1);
    }
    sort(a.begin(), a.end());
    for (int k = 0; k + 3 < n; ++k) {
        int target = x - a[k].first;
        if (target <= 0) continue;

    }
    return 0;
}
