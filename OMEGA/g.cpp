#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, b; cin >> a >> b;
    int p = a.size();
    int q = b.size();
    int Ana = 0, Carolina = 0;
    for (int i = 0; i < p; ++i) {
        char tmp = a[i];
        if (tmp >= '0' && tmp <= '9') Ana += (tmp - '0');
        if (tmp >= 'a' && tmp <= 'z') Ana += (tmp - 'a') + 10;
        if (tmp >= 'A' && tmp <= 'Z') Ana += 2 * ((tmp - 'A') + 10);
    }
    for (int i = 0; i < q; ++i) {
        char tmp = b[i];
        if (tmp >= '0' && tmp <= '9') Carolina += (tmp - '0');
        if (tmp >= 'a' && tmp <= 'z') Carolina += (tmp - 'a') + 10;
        if (tmp >= 'A' && tmp <= 'Z') Carolina += 2 * ((tmp - 'A') + 10);
    }
    if (Ana > Carolina) cout << "Ana " << Ana;
    else cout << "Carolina " << Carolina; 
    return 0;
}
