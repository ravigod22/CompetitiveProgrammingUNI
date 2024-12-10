#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    for (int i = 0; i < n; ) {
        int cnt1 = 0;
        while (i < n && s[i] == '1') ++i, cnt1++;
        if (i == n) break;
        if (s[i++] != '/') continue;
        int cnt2 = 0;
        while (i < n && s[i] == '2') ++i, cnt2++;
        ans = max(ans, 2 * min(cnt2, cnt1) + 1);
    }
    cout << ans << "\n";
    return 0;
}
