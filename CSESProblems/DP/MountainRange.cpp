#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int deg[N];
vector<int> G[N];

int main() {
    // Complexity O(n)
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<int> left, right;
    for (int i = 1; i <= n; ++i) {
        while (!left.empty() && a[i] >= a[left.back()]) {
            left.pop_back();
        }
        if (!left.empty()) {
            G[left.back()].push_back(i);
            deg[i]++;
        }
        left.push_back(i);
    }
    for (int i = n; i > 0; --i) {
        while (!right.empty() && a[i] >= a[right.back()]) {
            right.pop_back();
        }
        if (!right.empty()) {
            G[right.back()].push_back(i);
            deg[i]++;
        }
        right.push_back(i);
    }
    queue<int> Q;
    vector<int> dis(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        if (deg[i]) continue;
        Q.emplace(i);
        dis[i] = 1;
    }
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v : G[u]) {
            deg[v]--;
            if (deg[v] == 0) {
                Q.emplace(v);
                dis[v] = 1 + dis[u];
            }
        }
    }
    cout << *max_element(dis.begin(), dis.end()) << "\n";
    return 0;
}
