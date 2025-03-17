#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    string s; cin >> s;
    int n = 13; 
    // cin >> n;
    i64 ans = 0;
    for (int i = 0; i + n <= (int)s.size(); ++i) {
        i64 tmp = 1;
        for (int j = i; j < i + n; ++j) {
            tmp *= 1LL * (s[j] - '0');
        }
        ans = max(ans, tmp);
    }
    cout << ans << "\n";
    return 0;
}
