#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        string s, t; cin >> s >> t;
        swap(s[0], t[0]);
        cout << s << " " << t << "\n"; 
    }
    return 0;
}
