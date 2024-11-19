#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        map<int,int> need;
        map<int,int> have;
        for (int& e : a) cin >> e;
        for (int& e : b) cin >> e;
        int m; cin >> m;
        vector<int> d(m);
        for(int& e : d) cin >> e;
        for (int i = 0; i < m; ++i) {
            have[d[i]]++;
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) need[b[i]]++;
        }
        bool can = true;
        for (auto e : need) {
            if (have[e.first] < e.second) {
                can = false;
                break;
            }  
        }
        if (!can) {
            cout << "NO\n";
            continue;
        }
        bool could = false;
        for (int i = 0; i < n; ++i) {
            if (b[i] == d[m - 1]) could = true; 
        }
        cout << (could ? "YES\n" : "NO\n");
    }
    return 0;
}

