#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        string s; cin >> s;
        int n = s.size();
        string ans;
        for (int i = 0; i < n; ) {
            char tmp = s[i];
            int cnt = 0;
            while (i < n && tmp == s[i]) ++i, cnt++;
            if (i == n) {
                while (cnt--) ans += (tmp == '?' ? '1' : tmp);
            }
            else {
                char aux = s[i];
                while (cnt--) ans += (tmp == '?' ? aux : tmp);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
