#include <bits/stdc++.h>
using namespace std;

int main() {
    const int n = 12;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        string s; cin >> s;
        if ((int)s.size() == i) cnt++;
    }
    cout << cnt;
    return 0;
}
