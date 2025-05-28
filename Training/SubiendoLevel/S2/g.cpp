#include <bits/stdc++.h>
using namespace std;

int main() {
    int fquery = 0, squery = 0, res = 0;
    cout << "?";
    for (int i = 0; i < 100; ++i) {
        cout << " " << i;
    }
    cout << endl;
    cin >> fquery;
    res |= (fquery >> 7 << 7);
    cout << "?";
    for (int i = 0; i < 100; ++i) {
        cout << " " << ((i + 1) << 7);
    }
    cout << endl;
    cin >> squery;
    res |= (squery & ((1 << 7) - 1));
    cout << "! " << res << endl;
    return 0;
}

