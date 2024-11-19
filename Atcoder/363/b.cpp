#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t, p; cin >> n >> t >> p;
    vector<int> l(n);
    for (auto& e : l) cin >> e;
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (l[i] >= t) cnt++;
    }
    sort(l.rbegin(), l.rend());
    if (cnt < p) {
        p -= cnt;
        int tmp = 0;
        for (int i = 0; i < n; ++i) {
            if (l[i] >= t) continue;
            if (p) {
                tmp = t - l[i];
                p--;
            }
            else break;
        }
        ans = tmp;
    } 
    else ans = 0;
    cout << ans << "\n";
    return 0;
}
