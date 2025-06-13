#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n; 
    string s; cin >> n >> s;
    string xd = s;
    int idx = -1;
    char x;
    for (int i = 0; i < n; i++) {
        if (idx == -1 or (s[i] <= x)) {
            idx = i;
            x = s[i];
        }
    }
    int i = 0;
    while(i < n and s[i] == x) {
        i++;
    }
    if (i < n) swap(s[idx], s[i]);
    xd = min(xd, s);
    cout << xd << "\n";
    return 0;
}
