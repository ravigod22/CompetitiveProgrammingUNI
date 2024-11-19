#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ll long long
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;
const int INF = 1e9;

void solve() {
    // int
    string s; 
    while(cin >> s) {
        if(s == "E") {
            cout << "suricato\n";
        }
        if (s == "Sim,") {
            cout << "facochero\n";   
        }
        if (s == "Os") {
            cout << "leao\n";   
        }
    }

}


int main() {
    fastio;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }
}

