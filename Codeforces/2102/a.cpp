#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m, p, q;
        cin >> n >> m >> p >> q;
        if (n % p) cout << "YES\n";
        else {
            int bucket = n / p;
            cout << (bucket * q == m ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}

