#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, h; cin >> n >> h;
    vector<int> a(n);
    int cnt = 0;
    for (int& e : a) {
        cin >> e;
        if (e <= h) cnt += 1;
    }
    cout << cnt << "\n";
    return 0;
}
