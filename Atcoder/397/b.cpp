#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int ans = 0;
    const int n = s.size();
    bool odd = true;
    for (int i = 0; i < n; ++i) {
        if (odd) {
            if (s[i] == 'i') ans++, odd ^= 1;
            else ans += 2;
        }
        else {
            if (s[i] == 'o') ans++, odd ^= 1;
            else ans += 2;
        }
    }
    if (ans & 1) ans++;
    int dis = ans - n;
    cout << dis << "\n";
    return 0;
}

