#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d; cin >> n >> d;
    string s; cin >> s;
    reverse(s.begin(), s.end());
    for (int i = 0; i < n && d; ++i) {
        if (s[i] == '@') {
            s[i] = '.';
            d--;
        }
    }
    reverse(s.begin(), s.end());
    cout << s << "\n";
    return 0;
}
