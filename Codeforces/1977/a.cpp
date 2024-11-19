#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        if (n < m) {
            cout << "No\n";
            continue;
        }
        int remain = n - m;
        cout << (remain & 1 ? "No\n" : "Yes\n");
    }
    return 0;
}
