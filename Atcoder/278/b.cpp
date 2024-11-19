#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--) {
        int h, m; cin >> h >> m;
        for (int i = h; i <= 48; ++i) {
            int tmp = i % 24;
            if (i == h) {
                for (int j = m; j <= 59; ++j) {
                    int a = tmp / 10;
                    int b = tmp % 10;
                    int c = j / 10;
                    int d = j % 10;
                    swap(b, c);
                    int newhour = a * 10 + b;
                    int newmin = c * 10 + d;
                    if (newhour < 24 && newmin < 60) {
                        cout << tmp << " " << j << "\n";
                        return 0;
                    }
                }
            }
            else {
                for (int j = 0; j <= 59; ++j) {
                    int a = tmp / 10;
                    int b = tmp % 10;
                    int c = j / 10;
                    int d = j % 10;
                    swap(b, c);
                    int newhour = a * 10 + b;
                    int newmin = c * 10 + d;
                    if (newhour < 24 && newmin < 60) {
                        cout << tmp << " " << j << "\n";
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}

