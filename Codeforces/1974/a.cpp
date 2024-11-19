#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt;
	while (tt--) {
		int x, y; cin >> x >> y;
        if (y & 1) {
            int tmp = (y + 1) / 2;
            if (x <= 7 * tmp  + 4) {
                cout << tmp << "\n";
            } 
            else {
                x -= (7 * tmp + 4);
                int ans = (x + 14) / 15;
                cout << tmp + ans << "\n";
            }
        }
        else {
            int tmp = y / 2;
            if (x <= 7 * tmp) {
                cout << tmp << "\n";
            }
            else {
                x -= (7 * tmp);
                int ans = (x + 14) / 15;
                cout << tmp + ans << "\n";
            }
        }
	}
	return 0;
}
