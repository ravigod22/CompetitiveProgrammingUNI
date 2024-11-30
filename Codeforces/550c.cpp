#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    const int n = s.size();
    for (int i = 0; i < n; ++i) {
        if ((s[i] - '0') % 8 == 0) {
            cout << "YES\n";
            cout << s[i] << "\n";
            return 0;
        }
    }
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int p = (s[j] - '0');
            int q = (s[i] - '0');
            if ((2 * q + p) % 8 == 0) {
                cout << "YES\n";
                cout << s[i] << s[j] << "\n";
                return 0;
            }
        }
    }
    for (int i = 0; i + 2 < n; ++i) {
        for (int j = i + 1; j + 1 < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int p = (s[k] - '0');
                int q = (s[j] - '0');
                int r = (s[i] - '0');
                if ((p + 2 * q + 4 * r) % 8 == 0) {
                    cout << "YES\n";
                    cout << s[i] << s[j] << s[k] << "\n";
                    return 0;
                }
            }
        }
    }
    cout << "NO\n";
    return 0;
}
