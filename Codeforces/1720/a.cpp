#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        if (a == 0 && c == 0) cout << 0 << "\n";
        else if (a == 0 || c == 0) cout << 1 << "\n";
        else {
            long long tmp1 = 1LL * a * d;
            long long tmp2 = 1LL * b * c;
            if (tmp1 == tmp2) cout << 0 << "\n";
            else if(tmp1 % tmp2 == 0 || tmp2 % tmp1 == 0) cout << 1 << "\n";
            else cout << 2 << "\n";
        }
    }
    return 0;
}
