#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    for (char& e : s) {
        if (e == 'p') e = 'q';
        else if (e == 'q') e = 'p';
    }
    reverse(s.begin(), s.end());
    cout << s << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

