#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a(10);
    vector<int> b(10);
    iota(a.begin(), a.end(), 0);
    iota(b.begin(), b.end(), 0);
    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end(), greater<>());
    for (auto e : a) cout << e << " ";
    cout << "\n";
    for (auto e : b) cout << e << " ";
    return 0;
}
