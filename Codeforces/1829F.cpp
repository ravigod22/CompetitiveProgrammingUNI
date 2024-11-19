#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
const int inf = 2e9;
int n, m; 
vector<int> G[maxn];

void clear_graph() {
	vector<int> empty;
	for (int i = 0; i < maxn; ++i) {
		G[i] = empty;
	}
}
vector<int> BFS(int source) {
	vector<int> dis(n, inf);
	queue<int> q;
	dis[source] = 0;
	q.emplace(source);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : G[u]) {
			if (dis[v] == inf) {
				dis[v] = 1 + dis[u];
				q.emplace(v);
			}
		}
	}
	return dis;
}
void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		--u; --v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	for (int i = 0; i < n; ++i) {
		vector<int> d = BFS(i);
		set<int> s;
		for (int j = 0; j < n; ++j) {
            if (j == i) continue;
			if (d[j] != inf) {
				s.emplace(d[j]);
			}
		}
		if ((int)s.size() == 2) {
			int x = (int)G[i].size();
			int y = (int)G[G[i].back()].size() - 1;
			cout << x << " " << y << "\n";
            return;
		}
        s.clear();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	while (tt--) {
		solve();
		clear_graph();
	}
	return 0;
}
