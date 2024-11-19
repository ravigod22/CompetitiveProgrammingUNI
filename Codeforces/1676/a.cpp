#include <bits/stdc++.h>
using namespace std;

bool solve() {
    string s; cin >> s;
    int sum = 0;
    for (int i = 0; i < 3; ++i) sum += s[i] - '0';
    for (int i = 3; i < s.size(); ++i) sum -= s[i] - '0';
    return sum == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        cout << (solve() ? "YES\n" : "NO\n");
    }
    return 0;
}
