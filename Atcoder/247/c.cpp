#include <bits/stdc++.h>
using namespace std;

string f(int n) {
    if (n == 1) return "1";
    string tmp = to_string(n);
    string ans = f(n - 1) + " " + tmp + " " + f(n - 1);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    while (tt--) {
        int n; cin >> n;
        string ans = f(n);
        cout << ans << "\n";
    }
    return 0;
}

