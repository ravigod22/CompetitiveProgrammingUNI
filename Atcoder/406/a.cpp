#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    // a h : b m
    // c h : d m
    if (c <= a) {
        if (c == a) {
            if (b >= d) cout << "Yes\n";
            else cout << "No\n";
        }
        else cout << "Yes\n";
    }
    else cout << "No\n";
    return 0;
}
