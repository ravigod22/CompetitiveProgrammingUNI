#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int ans = 0;
    for (int i = 0; i < n; ) {
        char tmp = s[i];
        int cnt = 0;
        while (i < n && tmp == s[i]) ++i, cnt++;
        if (tmp == 'O') ans += (cnt / k);
    }
    cout << ans << "\n";
    return 0;
}
