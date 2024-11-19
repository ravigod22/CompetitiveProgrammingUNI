#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int a, b; cin >> a >> b;
        string s; cin >> s;
        if (a == 0 && b == 1) {
            if (s[0] == '?' || s[0] == '1') cout << 1 << "\n";
            else cout << -1 << "\n";
            continue;
        }
        if (a == 1 && b == 0) {
            if (s[0] == '?' || s[0] == '0') cout << 0 << "\n";
            else cout << -1 << "\n";
            continue;
        }
        int n = a + b;
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] == '?' && s[n - i - 1] == '?') continue;
            if (s[i] == '?' && s[n - i - 1] != '?') s[i] = s[n - i - 1];
            else if (s[i] != '?' && s[n - i - 1] == '?') s[n - i - 1] = s[i];
        }
        //cout << s << "\n";
        int one = count(s.begin(), s.end(), '1');
        int zero = count(s.begin(), s.end(), '0');
        //cout << one << " " << zero << "\n";
        auto f = [&] (string s) -> bool {
            for (int i = 0; i < s.size() / 2; ++i) {
                if (s[i] != s[s.size() - 1 - i]) return false;
            }
            return true;
        };
        if (one <= b && zero <= a) {
            //cout << "loop " << b - one << " " << a - zero << "\n";
            int j = 0;
            int tmp1 = b - one;
            while (tmp1 > 1 && j < n / 2) {
                if (s[j] == '?') {
                    s[j] = s[n - 1 - j] = '1'; 
                    tmp1 -= 2;
                }
                ++j;
            }
            //cout << "after 1" << "\n";
            //cout << s << "\n";
            int tmp2 = a - zero;
            j = 0;
            while (tmp2 > 1 && j < n / 2) {
                if (s[j] == '?') {
                    s[j] = s[n - 1 - j] = '0';
                    tmp2 -= 2;
                }
                ++j;
            }
            //cout << "after 0\n";
            //cout << s << "\n";
            //cout << tmp1 << " " << tmp2 << "\n";
            if (n & 1) {
                if (tmp2 == 1 && tmp1 == 0) {
                    if (s[n / 2] == '?') s[n / 2] = '0';
                    cout << (f(s) ? s : "-1") << "\n";
                }
                else if (tmp1 == 1 && tmp2 == 0) {
                    if (s[n / 2] == '?') s[n / 2] = '1';
                    cout << (f(s) ? s : "-1") << "\n";
                }
                else if (tmp1 == 0 && tmp2 == 0) {
                    cout << (f(s) ? s : "-1") << "\n";
                }
                else cout << -1 << "\n";
                
            }
            else {
                if (tmp2 == 0 && tmp1 == 0) {
                    cout << (f(s) ? s : "-1") << "\n";
                }
                else cout << -1 << "\n";
            }
        }
        else {
            cout << -1 << "\n";
            continue;
        }
    }
    return 0;
}

