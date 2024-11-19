#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1] && s[i] == "sweet" && i != n - 1) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}
