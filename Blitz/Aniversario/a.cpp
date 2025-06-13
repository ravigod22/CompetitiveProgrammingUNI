#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    string s;
    getline(cin , s); 
    string tmp;
    vector<int> a;
    s += " ";
    for (char e : s) {
        if (e == ' ') {
            a.push_back(stoi(tmp));
            tmp = "";
        }
        else {
            tmp += e;
        }
    }
    int n = a.size();
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        if (mp.count(a[i])) {
            cout << a[i] << "\n";
            return;
        }
        mp[a[i]]++;
    }
    cout << -1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    cin >> tt;
    cin.ignore();
    while (tt--) {
        solve();
    }
    return 0;
}


