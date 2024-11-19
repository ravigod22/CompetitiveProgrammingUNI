#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] <= 'z' && 'a' <= s[i]) continue;
        cout << i + 1;
        return 0;
    }
    return 0;
}
