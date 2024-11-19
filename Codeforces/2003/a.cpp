#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        if (s[0] != s[n - 1]) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    return 0;
}
