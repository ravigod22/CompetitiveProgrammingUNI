#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, z; cin >> x >> y >> z;
    if (x < y && y > 0) cout << abs(x);
    else if (x < y && y < 0 && y < z && z < 0) cout << abs(x);
    else if (x < y && y < 0 && y < z && z > 0) cout << 2 * abs(z) + abs(x);
    else if (x > y && y < 0) cout << abs(x);
    else if (x > y && x < 0) cout << abs(x);
    else if (x > y && y > 0 && z < y && z < 0) cout << 2 * abs(z) + abs(x);
    else if (x > y && y > 0 && z < y && z > 0) cout << abs(x);
    else cout << -1;
    return 0;
}

