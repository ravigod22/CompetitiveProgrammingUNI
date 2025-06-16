#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    int pnt = 0;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int pos, b;
            cin >> pos >> b;
            pos--;
            int cur = (pnt + pos) % n;
            a[cur] = b;
        }
        else if (op == 2) {
            int pos;
            cin >> pos;
            pos--;
            int cur = (pnt + pos) % n;
            cout << a[cur] << "\n";
        }
        else {
            int k;
            cin >> k;
            k %= n;
            pnt = (pnt + k) % n;
        }
    }
    return 0;
}

