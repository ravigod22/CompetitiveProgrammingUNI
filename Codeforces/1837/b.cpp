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
        int ans = 0;
        for (int i = 0; i < n; ) {
            char tmp = s[i];
            int cnt = 0;
            while (i < n && tmp == s[i]) cnt++, i++;
            ans = max(ans, cnt);
        }
        cout << ans + 1 << "\n";
    }
    return 0;
}
