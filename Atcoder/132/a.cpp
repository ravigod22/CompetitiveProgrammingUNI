#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    set<char> contein;
    for (int i = 0; i < s.size(); ++i) contein.emplace(s[i]);
    cout << (contein.size() == 2 ? "Yes\n" : "No\n");
    return 0;
}
