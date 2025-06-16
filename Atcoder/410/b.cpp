#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, q;
    cin >> n >> q;
    vector<int> b(n + 1, 0);
    while (q--) {
        int a;
        cin >> a;
        int pos;
        if (a > 0) {
            b[a] += 1;
            pos = a;
        }
        else {
            int mine = *min_element(b.begin() + 1, b.end());
            for (int i = 1; i <= n; ++i) {
                if (b[i] == mine) {
                    b[i] += 1;
                    pos = i;
                    break;
                }
            }
        }
        cout << pos << " ";
    }
    cout << "\n";
    return 0;
}

