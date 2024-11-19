#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 inf = 2e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        sort(a.begin(), a.end());
        int tmp = a.back();
        i64 ans = inf;
        vector<pair<int, int>> inval;
        for (int i = 0; i < n; ++i) {
            // a_i + k * t
            int aux = (tmp - a[i]) / k;
            if (aux & 1) {
                aux++;
                int l = a[i] + aux * k;
                int r = l + k - 1;
                inval.emplace_back(l, r);
            }
            else {
                int l = a[i] + aux * k;
                int r = l + k - 1;
                inval.emplace_back(l, r);
            }
        }
        int ansl = inval[0].first;
        int ansr = inval[0].second;
        for (int i = 1; i < inval.size(); ++i) {
            if (ansl <= inval[i].first) ansl = inval[i].first;
            if (inval[i].second <= ansr) ansr = inval[i].second;
        }
        if (ansl > ansr) {
            cout << -1 << "\n";
        }
        else cout << ansl << "\n";
    }
    return 0;
}
