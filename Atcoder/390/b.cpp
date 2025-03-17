#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    for (int i = 1; i + 1 < n; ++i) {
        if (1LL * a[i] * a[i] != 1LL * a[i - 1] * a[i + 1]) {
            cout << "No\n";
            return 0;
        }    
    }
    cout << "Yes\n";
    return 0;
}

