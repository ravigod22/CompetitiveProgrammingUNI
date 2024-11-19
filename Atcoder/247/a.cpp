#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    while (tt--) {
        string s;
        cin >> s;
        string tmp = s.substr(0, s.size() - 1);
        tmp = "0" + tmp;
        cout << tmp << "\n";
    }
    return 0;
}
