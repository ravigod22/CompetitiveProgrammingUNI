#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        string s; cin >> s;
        bool can = 0;
        for (int i = 1; i < (int)s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                can = 1;
                break;
            }
        }
        cout << (can ? 1 : (int)s.size()) << "\n";
    }
    return 0;
}

