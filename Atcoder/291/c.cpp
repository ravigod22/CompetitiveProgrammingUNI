#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    map<pair<int,int>, int> times;
    int x = 0, y = 0;
    times[{0, 0}]++;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R') x++;
        if (s[i] == 'L') x--;
        if (s[i] == 'U') y++;
        if (s[i] == 'D') y--;
        times[{x, y}]++;
    }
    for (auto e : times) {
        if (e.second > 1) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}
