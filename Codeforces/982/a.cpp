#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    string s; cin >> s;
    s = '0' + s + '0';
    bool can = true;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '1') {
            if (s[i - 1] == '1' or s[i + 1] == '1') can = false;
        }
        else if (s[i] == '0') {
            if (s[i - 1] == s[i + 1] && s[i - 1] == '0') can = false;
        }
    }
    cout << (can ? "Yes\n" : "No\n");
    return 0;
}
