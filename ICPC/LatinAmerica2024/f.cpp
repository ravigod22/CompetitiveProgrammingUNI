#include <bits/stdc++.h>
using namespace std;

string two = "X-";
string three = "-X-";

int main() {
    int n, k; cin >> k >> n;
    int init = n;
    if ((n + 2) / 3 <= k && k <= (n + 1) / 2) {
        string ans;
        while (k) {
            if (n < 3 * k) {
                ans += two;
                n -= 2;
            }
            else if (n == 3 * k) {
                ans += three;
                n -= 3;
            }
            k--;
        }
        if (ans.size() !=  init) ans.pop_back();
        assert(ans.size() == init);
        cout << ans << "\n";
    }
    else cout << "*\n";
    return 0;
}
