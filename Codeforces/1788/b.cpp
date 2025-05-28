#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        if (n & 1) {
            string num = to_string(n);
            string a, b;
            bool odd = true;
            for (int i = 0; i < num.size(); ++i) {
                int aux = num[i] - '0';
                if (aux % 2 == 0) {
                    a += char(aux / 2 + '0');
                    b += char(aux / 2 + '0');
                }
                else {
                    if (odd) {
                        a += char((aux + 1) / 2 + '0');
                        b += char((aux / 2) + '0');
                    }
                    else {
                        a += char((aux / 2) + '0');
                        b += char((aux + 1) / 2 + '0');
                    }
                    odd ^= 1;
                }
            }
            cout << stoi(a) << " " << stoi(b) << "\n";
        }
        else cout << n / 2 << " " << n / 2 << "\n";
    }
    return 0;
}
