#include <bits/stdc++.h>
using namespace std;

int main() {
    double x; cin >> x;
    if (x >= 38.0) cout << 1;
    else if (x < 38.0 && x >= 37.5) cout << 2;
    else cout << 3;
    cout << "\n";
    return 0;
}
