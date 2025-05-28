#include <bits/stdc++.h>
using namespace std;

int main() {
    string t, u; cin >> t >> u;
    int n = t.size(), m = u.size();
    bool exist = false;
    for (int i = 0; i + m <= n; ++i) {
        int p = 0;
        for (int j = 0; j < m; ++j) {
            if (t[i + j] == u[j] or t[i + j] == '?') p++;
        }
        if (p == m) exist = true;
    }
    cout << (exist ? "Yes" : "No") << "\n";
    return 0;
}
