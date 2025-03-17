#include <bits/stdc++.h>
using namespace std;

int f(int x) {
    int ans = 1;
    while (x--) ans *= 10;
    return ans;
}


int main() {
    int n; cin >> n;
    int ans = 0;
    for (int i = f(n); i < f(n + 1); ++i) {
        for (int j = f(n); j < f(n + 1); ++j) {
            int num = i * j;
            string palin = to_string(num);
            bool can = true;
            for (int k = 0; k < (int)palin.size(); ++k) {
                if (palin[k] != palin[(int)palin.size() - k - 1]) can = false;
            }
            if (can) ans = max(ans, num);
        }
    }
    cout << ans << "\n";
    return 0;
}
