#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int main() {
    int a, m;
    cin >> a >> m;
    cout << gcd(a, m) << "\n";
    return 0;
}
