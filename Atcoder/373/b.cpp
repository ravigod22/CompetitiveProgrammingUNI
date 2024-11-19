#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int pos[26];
    for (int i = 0; i < 26; ++i) {
        pos[s[i] - 'A'] = i + 1;
    }
    int ans = 0;
    for (int i = 1; i < 26; ++i) {
        ans += abs(pos[i] - pos[i - 1]);
    }
    cout << ans << "\n";
    return 0;
}
