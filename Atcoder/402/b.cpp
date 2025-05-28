#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> res;
    int q; cin >> q;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int x; cin >> x;
            res.push(x);
        }
        else {
            int num = res.front();
            res.pop();
            cout << num << "\n";
        }
    }
    return 0;
}

