#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long a, b, x; cin >> a >> b >> x;
    cout << (b / x) - (a / x) + (a % x == 0 ? 1 : 0);
    return 0;
}
