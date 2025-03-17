#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int sum = n * (n + 1) / 2;
    int sumsquare = sum * (2 * n + 1) / 3;
    sum *= sum;
    cout << sum - sumsquare << "\n";
    return 0;
}
