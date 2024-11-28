#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    bool close = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '"') {
            close ^= 1;
        }
        else if (s[i] == ',') {
            if (!close) {
                s[i] = '.';   
            }
        }
    }
    cout << s << "\n";
    return 0;
}
