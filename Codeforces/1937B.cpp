#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int cnt = 1;
    bool bottom = false;
    string result;
    result += s[0];
    for (int i = 1; i < n; ++i) {
        if (s[i] == t[i - 1] && !bottom) {
            cnt++;
            result += s[i];

        }
        else if (bottom || t[i - 1] == '0') {
            result += t[i - 1];
            bottom = true;
        }
        else if (s[i] == '0') {
            result += s[i];
            cnt = 1;
        }
    }
    result += t[n - 1];
    cout << result << "\n" << cnt << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
