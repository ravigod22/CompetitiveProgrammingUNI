#include <bits/stdc++.h>
using namespace std;

int con[10];

string sig(string s) {
    for(int i = 0; i < 10; i++) con[i] = 0;
    for (int i = 0; i < (int)s.size(); i++) con[s[i]-'0']++;
    string ans = "";
    for (int i = 0; i < 10; i++) {
        if (con[i]>0) {
            ans += to_string(con[i]) + to_string(i);
        }
    }
    return ans;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int ans = 1;
    while (s1 != s2 and ans <100) {
        s1 = sig(s1);
        ans++;
    }
    if (s1 == s2)
        if(ans > 100) 
            cout << "I’ m bored";
        else 
            cout << ans;
    else {
            cout << "Does not appear";
    }
    return 0;
}
