#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        string s; cin >> s;
        if (s.size() <= 2) {
            cout << "NO\n";
            continue;
        }
        string tmp = s.substr(0, 2);
        string aux = s.substr(2);
        if (tmp != "10") {
            cout << "NO\n";
            continue;
        }
        int e = stoi(aux);
        string another = to_string(e);
        if (aux != another || e == 0 || e < 2) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
    return 0;
}
