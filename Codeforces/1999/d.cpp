#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        string s, t;
        cin >> s;
        cin >> t;
        int ind = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '?') {
                if (ind < t.size()) {
                    s[i] = t[ind];
                    ++ind;
                }
                else s[i] = 'z';
            }
            else if (ind < t.size() && s[i] == t[ind]) ++ind;
        }
        if (ind == t.size()) {
            cout << "YES\n";
            cout << s << "\n";
        }
        else cout << "NO\n";
    }
    return 0;
}

