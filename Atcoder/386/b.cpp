#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    const int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; ) {
        char tmp = s[i];
        int cnt = 0;
        while (i < n && tmp == s[i]) ++i, cnt++;
        if (tmp == '0') {
            ans += (cnt + 1) / 2;
        }
        else ans += cnt;
    }
    cout << ans << "\n";
    return 0;
}
