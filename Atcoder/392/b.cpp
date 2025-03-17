#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<bool> exist(n + 1, 0);
    int cnt = n;
    for (int i = 0; i < m; ++i) {
        int x; cin >> x;
        if (x <= n) exist[x] = true, cnt--;
    }
    cout << cnt << "\n";
    for (int i = 1; i <= n; ++i) {
        if (exist[i]) continue;
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}

