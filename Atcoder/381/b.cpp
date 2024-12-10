#include <bits/stdc++.h>
using namespace std;

bool solve() {
    string s; cin >> s;
    const int n = s.size();
    if (n & 1) return 0;
    bool exist[26];
    memset(exist, 0, sizeof(exist));
    for (int i = 0; i < n; i += 2) {
        if (s[i] != s[i + 1]) return 0;
        if (exist[s[i] - 'a']) return 0;
        exist[s[i] - 'a'] = 1;
    }
    return 1;
}

int main() {
    cout << (solve() ? "Yes" : "No") << "\n";
    return 0;
}
