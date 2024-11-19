#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        i64 ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == '1') continue;
            for (int j = i; j <= n; j += i) {
                if (s[j - 1] == '1') break;
                if (s[j - 1] == '2') continue;
                s[j - 1] = '2';
                ans += i;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

