#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; 
    while (cin >> s) {
        int cntpos = 0;
        int cntneg = 0;
        int n = s.size();
        vector<pair<char,int>> v;
        for (int i = 0; i < n; ) {
            char tmp = s[i];
            int cnt = 0;
            while (tmp == s[i] && i < n) {
                cnt++;
                ++i;
            }
            v.emplace_back(
        }
    }
    return 0;
}

