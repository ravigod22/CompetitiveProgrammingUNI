#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char,char> change;
    vector<bool> exist(27, false);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        char c, d;
        cin >> c >> d;
        change[c] = d;
        exist[c - 'a'] =  true;
    }
    string result;
    for (int i = 0; i < n; ++i) {
        if (exist[s[i] - 'a']) {
            
        }
        else {
            result += s[i];
        }
    }
    return 0;
}
