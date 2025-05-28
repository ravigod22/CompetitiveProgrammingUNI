#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s(n, '-');
    if (n & 1) {
        s[n / 2] = '=';
    }
    else {
        s[(n - 1) / 2] = '=';
        s[n / 2] = '=';
    }
    cout << s << "\n";
    return 0;
}
