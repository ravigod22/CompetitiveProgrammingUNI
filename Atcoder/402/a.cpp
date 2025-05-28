#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    string ans;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= 'a') continue;
        ans += s[i];
    }
    cout << ans << "\n";
    return 0;
}
