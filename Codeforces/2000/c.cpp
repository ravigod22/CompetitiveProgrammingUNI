#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        int m; cin >> m;
        vector<string> s(m);
        for (auto& e : s) cin >> e;
        for (int i = 0; i < m; ++i) {
            string tmp = s[i];
            if (tmp.size() != n) {
                cout << "NO\n";
                continue;
            }
            map<char, int> mp;
            map<int, char> mp2;
            bool could = true;
            for (int j = 0; j < n; ++j) {
                char c = tmp[j];
                int e = a[j];
                if (mp.count(c)) {
                    if (mp[c] != e) {
                        could = false;
                        break;
                    }
                }
                else {
                    mp[c] = e;
                }
                if (mp2.count(e)) {
                    if (mp2[e] != c) {
                        could = false;
                        break;
                    }
                }
                else {
                    mp2[e] = c;
                }
            }
            cout << (could ? "YES\n" : "NO\n");
            mp.clear();
            mp2.clear();
        }
    }
    return 0;
}
