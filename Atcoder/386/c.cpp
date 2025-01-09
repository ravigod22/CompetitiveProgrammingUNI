#include <bits/stdc++.h>
using namespace std;

int main() {
    int k; cin >> k;
    string s, t; cin >> s >> t;
    int n = s.size();
    int m = t.size();
    if (abs(n - m) <= 1) {
        if (n < m) {
            int j = 0;
            for (int i = 0; i < m && j < n; ++i) {
                if (t[i] == s[j]) ++j;
            }
            cout << (j == n ? "Yes" : "No") << "\n";
        }
        else if (n > m) {
            int j = 0;
            for (int i = 0; i < n && j < m; ++i) {
                if (s[i] == t[j]) j++;
            }
            cout << (j == m ? "Yes" : "No") << "\n";
        }
        else {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] != t[i]) cnt++;
            }
            cout << (cnt < 2 ? "Yes" : "No") << "\n";
        }
    }
    else cout << "No\n";
    return 0;
}
