#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int elem[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    iota(elem, elem + maxn, 1);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> pos(n + 1, -1);
        bool one;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] == 1) one = (i & 1);
        }
        int k = (one ? 2 : 1);
        int maxl = (n / 2) - 1; 
        set<int> s;
        set<int> perm(elem, elem + n);
        while (maxl) {
            s.emplace(a[k]);
            maxl--;
            k += 2;
        }
        while (s.size()) {
            auto e = *s.begin();
            pos[e] = *perm.rbegin();
            perm.erase(pos[e]);
            s.erase(e);
        }
        for (int i = n; i > 0; --i) {
            if (pos[i] != -1) continue;
            pos[i] = *perm.begin();
            perm.erase(pos[i]);
        }
        for (int i = 0; i < n; ++i) {
            cout << pos[a[i]] << " \n"[i + 1 == n];
        }
    }
    return 0;
}
