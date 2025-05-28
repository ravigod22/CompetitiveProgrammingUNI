#include <bits/stdc++.h>
using namespace std;

int main() {
    int sum = 15;
    for (int i = 0; i < 4; ++i) {
        int x; cin >> x;
        sum -= x;
    }
    cout << sum << "\n";
    return 0;
}
