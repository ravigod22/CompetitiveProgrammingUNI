#include <bits/stdc++.h>
using namespace std;
const int maxm = 2e5 + 10;
vector<long long> pos[maxm];

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= n) continue;
        int lo = (a[i] >= 0 ? 1 : (i - a[i]) / (i + 1));
        int hi = min(m + 1, (n - a[i] + i) / (i + 1));
        for (int j = lo; j < hi; ++j) pos[j].emplace_back(a[i] + 0ll + 1ll * (i + 1) * j);
    }
    for (int i = 1; i <= m; ++i) {
        if (pos[i].size() == 0) cout << 0 << "\n";
        else {
            vector<long long> tmp = pos[i];
            set<long long> s;
            for (int i = 0; i <= tmp.size(); ++i) s.emplace(1ll * i);
            for (int i = 0; i < tmp.size(); ++i) {
                s.erase(tmp[i]);
            }
            cout << *s.begin() << "\n";
            s.clear();
        }
    }
    return 0;
}

