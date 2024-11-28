#include <bits/stdc++.h>
using namespace std;

int ruleta(int n) {
    if (n == 1) return 1;
    if (n & 1) {
        return 2 * ruleta(n / 2) + 1;
    }
    else return 2 * ruleta(n / 2) - 1;
}

int main() {
    int n; cin >> n;
    cout << ruleta(n) << "\n";
    return 0;
}
