#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> result(n);
    for (int& e : a) cin >> e;
    for (int i = 0; i < n; ++i) {
        int mov = ((i + a[i]) % n + n) % n;
        if (a[i] != 0) result[i] = a[mov];
        else result[i] = a[i];
    }
    for (int e : result) cout << e << " ";
    cout << endl;
    return 0;
}
