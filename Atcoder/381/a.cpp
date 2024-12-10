#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n; cin >> n;
    string s; cin >> s;
    if (n % 2 == 0) return 0;
    int mid = n / 2;
    if (s[mid] != '/') return 0;
    for (int i = 0; i < mid; ++i) {
        if (s[i] != '1') return 0;
    }
    for (int i = mid + 1; i < n; ++i) {
        if (s[i] != '2') return 0;
    }
    return 1;
}

int main() {
    cout << (solve() ? "Yes" : "No") << "\n";
    return 0;
}
