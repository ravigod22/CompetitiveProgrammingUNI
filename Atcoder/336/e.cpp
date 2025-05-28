#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
string num;

int f(int pos, int sum, int k, bool borde) {
    if (pos == num.size()) return k == 0 ? 1 : 0;
    int ans = 0;
    if (borde) {
        int digit = num[pos] - '0';
        for (int i = 0; i <= digit; ++i) {
            ans += f(pos + 1, sum + i, (k * 10 + i) % (sum + i), i == digit);
        }
    }
    else {
        for (int i = 0; i < 10; ++i) {
            ans += f(pos + 1, sum + i, (k * 10 + i) % (sum + i), 0); 
        }
    }
    return ans;
}

int main() {
    cin >> num;
    int ans = 0;
    for (int i = 1; i <= 20; ++i) {
        ans += f(0, i, 0, 1);
    }
    cout << ans << "\n";
    return 0;
}
