#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    char a1, a2; cin >> a1 >> a2;
    string s; cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] != a1) s[i] = a2;
    }
    cout << s << "\n";
    return 0;
}
