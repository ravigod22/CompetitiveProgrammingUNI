#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d; cin >> n >> d;
    string s; cin >> s;
    int cnt = count(s.begin(), s.end(), '.');
    cout << cnt + d << "\n";
    return 0;
}
