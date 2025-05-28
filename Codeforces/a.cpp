#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main () {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << "\n";
        cout << 1 << "\n";
        return 0;
    }
    cout << (n / 2) << "\n";
    for (int i = 2; i <= n; i += 2) cout << i << " ";
    cout << "\n";
    return 0;
}
