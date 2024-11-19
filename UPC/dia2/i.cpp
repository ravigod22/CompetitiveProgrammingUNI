#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        string a, b; cin >> a >> b;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        auto sum = [&] (string& x, string& y) -> long long {
            long long a1 = stoll(x);
            long long a2 = stoll(y);
            return a1 + a2;
        };
        long long tmp = sum(a, b);
        string aux = to_string(tmp);
        reverse(aux.begin(), aux.end());
        int ind = 0;
        while (aux[ind] == '0') ind++;
        string ans = aux.substr(ind);
        cout << ans << "\n";
    }
    return 0;
}
