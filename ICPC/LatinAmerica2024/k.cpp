#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    string s; 
    cin >> k >> s;
    int n = s.size();
    if (k == 2) {
        string a, b;
        for (int i = 0; i < n; ++i) {
            a += (i & 1 ? '1' : '0');
            b += (i & 1 ? '0' : '1');
        }
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; ++i) {
            cnt1 += (s[i] != a[i]);
            cnt2 += (s[i] != b[i]);
        }
        if (cnt1 < cnt2) cout << cnt1 << " " << a;
        else cout << cnt2 << " " << b;
        cout << "\n";
    }
    else {
        int ans = 0;
        string result;
        for (int i = 0; i < n; ) {
            int cnt = 0;
            char tmp = s[i];
            while (i < n && tmp == s[i]) ++i, cnt++;
            string aux(cnt, tmp);
            ans += cnt / k;
            int pos = k - 1;
            if (cnt % k) {
                for (int j = 0; j < (cnt / k); ++j, pos += k) {
                    aux[pos] = (tmp == '1' ? '0' : '1'); 
                }
            }
            else {
                for (int j = 0; j < (cnt / k); ++j, pos += k) {
                    aux[(j + 1 == (cnt / k) ? pos - 1 : pos)] = (tmp == '1' ? '0' : '1');   
                }
            }
            result += aux;
        }
        cout << ans << " " << result << "\n";
    }
    return 0;
}
