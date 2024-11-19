#include <bits/stdc++.h>
using namespace std;

bool solve() {
    map<char, int> mp;
    mp['R'] = 1;
    mp['G'] = 2;
    mp['B'] = 3;
    int s[3];
    int t[3];
    for (int i = 0; i < 3; ++i) {
        char x; cin >> x;
        s[i] = mp[x];
    }
    for (int i = 0; i < 3; ++i) {
        char x; cin >> x;
        t[i] = mp[x];
    }
    int ans = 0;
    for (int i = 0; i < 3; ++i) {
        if (s[i] != t[i]) ans++;
    }
    if (ans == 2) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--) {
        cout << (solve() ? "Yes\n" : "No\n");
    }
    return 0;
}

