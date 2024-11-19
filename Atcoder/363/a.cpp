#include <bits/stdc++.h>
using namespace std;

int main() {
    int r; cin >> r;
    if (r < 100) cout << 100 - r;
    else if (r < 200) cout << 200 - r;
    else if (r < 300) cout << 300 - r;
    return 0;
}
