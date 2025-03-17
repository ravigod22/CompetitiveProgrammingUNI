#include <bits/stdc++.h>
using namespace std;

int main() {
    const int n = 100;
    string num[n];
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        reverse(num[i].begin(), num[i].end());
    }
    string ans;
    int carry = 0;
    for (int j = 0; j < 50; ++j) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += num[i][j] - '0';
        }
        sum += carry;
        carry = sum / 10;
        sum %= 10;
        ans += char(sum + '0');
    }
    reverse(ans.begin(), ans.end());
    ans = to_string(carry) + ans;
    for (int i = 0; i < 10; ++i) cout << ans[i];
    cout << "\n";
    return 0;
}
