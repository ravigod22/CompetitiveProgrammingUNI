#include <bits/stdc++.h>
using namespace std;
const string exclude = "ABC316";

int main() {
    string s;
    cin >> s;
    if (s == exclude) {
        cout << "No\n";
        return 0;
    }
    string tmp = s.substr(3);
    int number = stoi(tmp);
    if (number == 0 || number > 349) cout << "No\n";
    else cout << "Yes\n";
    
    return 0;
}
