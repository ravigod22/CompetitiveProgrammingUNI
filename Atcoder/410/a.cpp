#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    int k;
    cin >> k;
    int cnt = 0;
    for (int e : a) cnt += (e >= k);
    cout << cnt << "\n";
    return 0;
}
