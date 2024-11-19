#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, k, l;
vector<int> G1[maxn];
vector<int> G2[maxn];
int road[maxn];
int rail[maxn];

void DFS(int u, int opcion) {
	if (opcion == 1) {
        road[u] = 1;
        for (int v : G1[u]) {
            if (road[v] != 0) continue;
            DFS(v, 1);
        }
    }
    if (opcion == 2) {
        rail[u] = 1;
        for (int v : G2[u]) {
            if (rail[v] != 0) continue;
            DFS(v, 2);
        }
    } 
}

void DFS_init(int opcion) {
	for (int i = 0; i < n; ++i) {
		if (opcion == 1) {
			if (G1[i].size() == 0) continue;
			DFS(i, 1);
		}
		else {
			if (G2[i].size() == 0) continue;
			DFS(i, 2);
		} 
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	memset(road, 0, sizeof(road));
	memset(rail, 0, sizeof(rail));
	cin >> n >> k >> l;
	for (int i = 0; i < k; ++i) {
		int u, v; cin >> u >> v;
		u--; v--;
		G1[u].emplace_back(v);
		G1[v].emplace_back(u);
	}
	for (int i = 0; i < l; ++i) {
		int u, v; cin >> u >> v;
		u--; v--;
		G2[u].emplace_back(v);
		G2[v].emplace_back(u);
	}
	DFS_init(1);
	DFS_init(2);
	for (int i = 0; i < n; ++i) {
		cout << (road[i] + rail[i]) << " \n"[i + 1 == n];
	}
	return 0;
}
