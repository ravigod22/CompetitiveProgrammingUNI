#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int E = 30;

int in[E];
bool marked[E][E];
vector<int> G[E];

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 1; j < s.size(); j++) {
            int u = s[j - 1] - 'a';
            int v = s[j] - 'a';
            if (u == v or marked[u][v]) continue;
            G[u].push_back(v);
            in[v] += 1;
            marked[u][v] = 1;
        }
    }
    queue<int> Q;
    vector<int> order;
    for (int i = 0; i < 26; i++) {
        if (in[i] == 0) Q.push(i);
    }
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        order.push_back(u);
        for (int v : G[u]) {
            in[v]--;
            if (in[v] == 0) Q.push(v);
        }
    }
    if (order.size() != 26) cout << "NAO\n";
    else {
        cout << "SIM\n";
        string ans;
        for (int i = 0; i < 26; i++) {
            ans.push_back('a' + order[i]);
        }
        cout << ans << "\n";
    }


    return 0;
}
