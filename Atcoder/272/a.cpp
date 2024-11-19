#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    int aux = accumulate(a.begin(), a.end(), 0);
    cout << aux;
    return 0;
}
