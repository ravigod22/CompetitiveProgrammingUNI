#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    if (n < 0) {
        cout << 0;
        return 0;
    }
    string t = to_string(n);
    int ans = 0;
    for (int i = 0; i < t.size(); ++i) {
        ans += (t[i] - '0');
    }
    cout << ans;
    return 0;
}
