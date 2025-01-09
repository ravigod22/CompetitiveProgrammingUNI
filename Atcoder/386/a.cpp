#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> a;
    for (int i = 0; i < 4; ++i) {
        int x; cin >> x;
        a.emplace(x);
    }
    cout << ((int)a.size() == 2 ? "Yes" : "No");
    return 0;
}
