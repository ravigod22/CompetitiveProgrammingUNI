#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> a[m];
    for (int i = 0; i < m; ++i) {
        int k; cin >> k;
        for (int j = 0; j < k; ++j) {
            int x; cin >> x;
            x--;
            a[i].push_back(x);
        }
    }
    vector<int> b(n);
    for (int& e : b) cin >> e, e--;
    vector<int> id(n);
    for (int i = 0; i < n; ++i) {
        id[b[i]] = i;
    }
    vector<int> cnt(n, 0);
    for (int i = 0; i < m; ++i) {
        int maxe = 0;
        for (int e : a[i]) {
            maxe = max(maxe, id[e]);
        }
        cnt[maxe]++;
    }
    for (int i = 1; i < n; ++i) cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; ++i) cout << cnt[i] << "\n";
    return 0;
}

