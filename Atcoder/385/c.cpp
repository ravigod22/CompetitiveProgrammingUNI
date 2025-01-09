#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            vector<int> tmp;
            for (int k = i; k < n; k += j) {
                tmp.emplace_back(a[k]);
            }
            for (int k = 0; k < (int)tmp.size(); ) {
                int aux = tmp[k];
                int cnt = 0;
                while (k < (int)tmp.size() && tmp[k] == aux) ++k, cnt++;
                ans = max(ans, cnt);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

