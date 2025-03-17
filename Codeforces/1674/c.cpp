#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        string s, t; cin >> s >> t;
        if (t.size() == 1) {
            if (t[0] == 'a') cout << 1 << "\n";
            else cout << (1LL << (int)s.size()) << "\n";
        }
        else {
            int cnt = count(t.begin(), t.end(), 'a');
            cout << (cnt ? -1LL : (1LL << (int)s.size())) << "\n";
        }
    }
    return 0;
}
