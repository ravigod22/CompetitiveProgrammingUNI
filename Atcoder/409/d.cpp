#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n == 1) {
            cout << s << "\n";
            continue;
        }
        int pos = 1;
        string ans;
        ans += s[0];
        while (pos < n && s[pos - 1] - 'a' <= s[pos] - 'a') {
            ans += s[pos++];
        }
        char cur = s[pos - 1];
        ans.pop_back();
        while (pos < n && s[pos] - 'a' <= cur - 'a') {
            ans += s[pos++];
        }
        ans += cur;
        while (pos < n) ans += s[pos++];
        cout << ans << "\n";
    }
    return 0;
}
