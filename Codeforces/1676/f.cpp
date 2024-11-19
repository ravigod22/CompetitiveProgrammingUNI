#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto& e : a) cin >> e;
    sort(a.begin(), a.end());
    vector<pair<int, int>> times;
    for (int i = 0; i < n; ) {
        int aux = a[i];
        int cnt = 0;
        while (i < n && a[i] == aux) {
            ++cnt;
            ++i;
        }
        times.emplace_back(aux, cnt);
    }
    int l = -1, r = -2;
    for (int i = 0; i < times.size(); ++i) {
        int init = times[i].first;
        bool exist = false;
        while (i + 1 < times.size() && times[i + 1].first - times[i].first == 1 && times[i + 1].second >= k && times[i].second >= k) {
            ++i;
            exist = true;
        } 
        int ending = (exist ? times[i].first : init);
        if (!exist) {
            if (times[i].second >= k) {
                if (r - l < 0) {
                    r = times[i].first;
                    l = times[i].first;
                }
            }
        }
        else {
            if (r - l < ending - init) {
                r = ending;
                l = init;
            }
        }
    }
    if (l == -1) cout << -1 << "\n";
    else cout << l << " " << r << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

