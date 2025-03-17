#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m; cin >> n >> m;
    int leave = 2 * n * m;
    int pos = 1;
    bool can = true, newest = true;
    int right, left, L, R;
    while (leave--) {
        int x; cin >> x;
        if (!can) continue;
        if (newest) {
            right = ((2 * pos) - 1) * m;
            left = right + 1;
            L = right - m;
            R = left + m;
            pos++;
            newest = false;
        }
        if (right > L && right == x) {
            right--;
        }
        else if (left < R && left == x) {
            left++;
        }
        else {
            can = false;
            continue;
        }
        if (right == L && left == R) newest = true;
    }
    cout << (can ? "yes" : "no");
    return 0;
}


