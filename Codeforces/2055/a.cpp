#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, a, b; cin >> n >> a >> b;
        int dis = abs(a - b) - 1;
        cout << (dis & 1 ? "YES" : "NO") << "\n";
    }
    return 0;
}
