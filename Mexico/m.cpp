#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    map<string, string> mp;
    for (int i = 0; i < n; ++i) {
        string p, a; cin >> p >> a;
        mp[p] = a;
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string x; cin >> x;
        string ans;
        for (auto e : x) {
            if ('a' <= e && e <= 'z') ans += 'l';
            if ('A' <= e && e <= 'Z') ans += 'u';
            if ('0' <= e && e <= '9') ans += 'd';
        }
        if (mp.count(ans)) {
            cout << mp[ans] << "\n";
        }
        else cout << "Liar!\n";
    }
    return 0;
}
