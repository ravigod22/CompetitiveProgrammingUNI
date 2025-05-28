#include <bits/stdc++.h>
using namespace std;


int main() {
    string s;
    cin >> s;
    vector<int> digit(10, 0);
    iota(digit.begin(), digit.end(), 0);
    reverse(s.begin(), s.end());
    int cnt = s.size();
    for (char e : s) {
        int d = digit[e - '0'];
        cnt += d;
        for (int i = 0; i < 10; ++i) {
            digit[i] = (digit[i] - d + 10) % 10;
        }
    }
    cout << cnt << "\n";
    return 0;
}
