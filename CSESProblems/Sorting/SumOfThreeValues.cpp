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
    for (int k = 0; k + 2 < n; ++k) {
        int target = x - a[k].first;
        if (target <= 0) continue;
        for (int i = k + 1, j = n - 1; i < j; ) {
            if (a[i].first + a[j].first < target) {
                ++i;
            }
            else if (a[i].first + a[j].first > target) {
                j--;
            }
            else {
                cout << a[k].second << " " << a[i].second << " " << a[j].second;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
