#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a(3);
    for (int& e : a) cin >> e;
    sort(a.begin(), a.end());
    cout << (a[0] * a[1] == a[2] ? "Yes\n" : "No\n");
    return 0;
}
