#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    long long k; cin >> k;
    if (n & 1) {
        string ans;
        for (int i = n - 1; i >= 0; --i) {
            if (k & (1ll << i)) ans += ')';
            else ans += '(';
        }
        cout << ans << "\n";
    }
    else {
        
    }
    return 0;
}
