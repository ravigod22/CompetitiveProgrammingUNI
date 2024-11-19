#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    int cnt = 0;
    for (int i = 0; i + 2 < n; ++i) {
        int min_e = min({a[i], a[i + 1], a[i + 2]});
        int max_e = max({a[i], a[i + 1], a[i + 2]});
        if (a[i + 1] != min_e && a[i + 1] != max_e) cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
