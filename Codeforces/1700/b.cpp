#include <bits/stdc++.h>
using namespace std;

string operation(string major, string minor) {
    string ans;
    reverse(major.begin(), major.end());
    reverse(minor.begin(), minor.end());
    int n = major.size();
    int carry = 0;
    for (int i = 0; i < n; ++i) {
        int a = major[i] - '0';
        int b = minor[i] - '0';
        if (a >= b + carry) {
            int dif = a - b - carry ;
            ans += (char)(dif + '0');
            carry = 0;
        }
        else {
            int dif = 10 + a - b - carry;
            ans += (char)(dif + '0');
            carry = 1;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        if (s[0] != '1') {
            string tmp(n + 1, '1');
            s = '0' + s;
            string result = operation(tmp, s);
            result = result.substr(1);
            cout << result << "\n";
        }
        else {
            string tmp(n, '3');
            string result = operation(tmp, s);
            cout << result << "\n";
        }
    }
    return 0;
}

