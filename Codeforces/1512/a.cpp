#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<pair<int, int>> a;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            a.emplace_back(x, i + 1);
        }
        sort(a.begin(), a.end());
        if (a[0].first == a[1].first) cout << a[n - 1].second << "\n";
        else if (a[n - 1].first == a[n - 2].first) cout << a[0].second << "\n";
    }
    return 0;
}
