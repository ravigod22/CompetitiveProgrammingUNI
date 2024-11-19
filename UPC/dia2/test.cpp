#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 1 << 31;
    cout << 31 - __builtin_clz(n) << "\n";
    return 0;
}
