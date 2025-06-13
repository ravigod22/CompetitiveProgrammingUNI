#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

const int N = 1e6 + 1;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};
vector<int> divi[N];
int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

void precomputation() {
    for (int i = 1; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            divi[j].push_back(i);
        }
    }
}

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void solve() {
    string s;
    string t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int common = gcd(n, m);
    vector<int> possible;
    for (int e : divi[common]) {
        bool can = true;
        for (int i = 0; i < e; ++i) {
            if (s[i] != t[i]) can = false; 
        }
        if (can) possible.push_back(e);
    }
    int ans = 0;
    for (int e : possible) {
        string tmp1 = s.substr(0, e) + "$" + s.substr(e);
        string tmp2 = t.substr(0, e) + "$" + s.substr(e);
        vector<int> p = z_function(tmp1);
        vector<int> q = z_function(tmp2);
        bool can = true;
        for (int i = e + 1; i < tmp1.size(); i += e)
            if (p[i] != e) can = false;
        for (int i = e + 1; i < tmp2.size(); i += e) {
            if (q[i] != e) can = false;
        }
        if (can) ans += 1;
    }
    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    precomputation();
    int tt = 1; 
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}



