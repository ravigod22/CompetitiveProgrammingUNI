#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    bool can = false;
    for (int i = 0; i < n; ++i) {
        if (s[i] == t[i] && s[i] == 'o') can = true;
    }
    cout << (can ? "Yes" : "No") << "\n";
    return 0;
}
