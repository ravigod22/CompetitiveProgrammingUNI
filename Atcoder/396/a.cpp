#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    for (int i = 2; i < n; ++i) {
        if (a[i - 2] == a[i - 1] && a[i - 1] == a[i]) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}
