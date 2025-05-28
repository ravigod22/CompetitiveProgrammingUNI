#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; ++i) {
        cin >> movies[i].first >> movies[i].second;
    }
    sort(movies.begin(), movies.end(), [&] (auto x, auto y) {
        return x.second < y.second;
    });
    int l = -1;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (movies[i].first >= l) {
            ans += 1;
            l = movies[i].second;
        }
    }
    cout << ans << "\n";
    return 0;
}
