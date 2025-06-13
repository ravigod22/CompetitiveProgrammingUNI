#include <bits/stdc++.h>
using namespace std;
string s, t;
int n, m;

string f(string a) {
    int dis = a.size();
    if (dis & 1) {
        return a;
    }
    string L = f(a.substr(0, dis / 2));
    string R = f(a.substr(dis / 2));
    return min(L + R, R + L);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s >> t;
    cout << (f(s) == f(t) ? "YES" : "NO") << "\n";
    return 0;
}
