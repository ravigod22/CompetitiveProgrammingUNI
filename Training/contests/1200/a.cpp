#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<pair<int, int>> a;
        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            a.emplace_back(x, i);
            cnt[x]++;
        }
        sort(a.begin(), a.end());
        bool could = true;
        for (int i = 1; i <= n; ++i) {
            if (cnt[i] >= 3) could = false;
        } 
        if (!could) {
            cout << "NO\n";
            continue;
        }
        vector<int> p(n, -1);
        vector<int> q(n, -1);
        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 1);
        set<int> p1(perm.begin(), perm.end());
        set<int> q1(perm.begin(), perm.end());
        for (int i = 0; i < n; ++i) {
            if (cnt[a[i].first] == 2) {
                p[a[i].second] = a[i].first;
                q[a[i + 1].second] = a[i].first;
                p1.erase(a[i].first);
                q1.erase(a[i].first);
                ++i;
            }
            else {
                p[a[i].second] = a[i].first;
                q[a[i].second] = a[i].first;
                p1.erase(a[i].first);
                q1.erase(a[i].first);
            }
        }    
    }
    return 0;
}
