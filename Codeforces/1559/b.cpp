#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        int f = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] != '?') {
                f = i;
                break;
            }
        }
        if (f == -1) {
            for (int i = 0; i < n; ++i) {
                s[i] = (i & 1 ? 'R' : 'B');
            }
            cout << s << "\n";
            continue;
        }
        for (int i = f - 1; i >= 0; --i) {
            if (s[i + 1] == 'R') s[i] = 'B';
            else s[i] = 'R';
        }
        for (int i = f + 1; i < n; ++i) {
            if (s[i] != '?') continue;
            if (s[i - 1] == 'R') s[i] = 'B';
            else s[i] = 'R';
        }
        cout << s << "\n";
    }
    return 0;
}
