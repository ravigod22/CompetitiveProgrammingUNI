#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        string s; cin >> s;
        const int n = s.size();
        int one = 0, zero = n - 1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') one = max(one, i);
            if (s[i] == '0') zero = min(zero, i);
        }
        cout << (zero - one + 1) << "\n";
    }
    return 0;
}

