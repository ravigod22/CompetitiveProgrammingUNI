#include <bits/stdc++.h>


using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int last = 0;
    for (int i = 0; i < n; ++i) {
        int need = a[i] - last;
        if (need > s) {
            cout << "No\n";
            return 0;
        }
        last = a[i];
    }
    cout << "Yes\n";
    return 0;
}
