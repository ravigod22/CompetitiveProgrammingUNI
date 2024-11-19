#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    string t; cin >> t;
    int s1 = abs((s[0] - 'A' + 1) - (s[1] - 'A' + 1));
    int t1 = abs((t[0] - 'A' + 1) - (t[1] - 'A' + 1));
    if ((s1 == 1 || s1 == 4) && (t1 == 1 || t1 == 4)) cout << "Yes\n";
    else if ((s1 == 2 || s1 == 3) && (t1 == 2 || t1 == 3)) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
