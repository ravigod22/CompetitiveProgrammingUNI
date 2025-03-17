#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        string s; cin >> s;
        s.pop_back();
        s.pop_back();
        s += 'i';
        cout << s << "\n";
    }
    return 0;
}
