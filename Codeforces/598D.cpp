#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int mxn = 1e3 + 10;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int n, m, k, cnt, view;
char grid[mxn][mxn];
int dis[mxn][mxn];
bool vis[mxn][mxn];
vector<pair<int,int>> tmp;


void init() {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			dis[i][j] = inf;
}
void DFS1(int x, int y) {
	int cnt_tmp = 0;
	for (int i = 0; i < 4; ++i) {
		int ni = x + dx[i];
		int nj = y + dy[i];
		if (ni < 0 || ni > n || nj < 0 || nj > m) continue;
		if (grid[ni][nj] == '*') ++cnt_tmp;
	}
	dis[x][y] = cnt_tmp;
	for (int i = 0; i < 4; ++i) {
		int ni = x + dx[i];
		int nj = y + dy[i];
		if (ni < 0 || ni > n || nj < 0 || nj > m) continue;
		if (grid[ni][nj] != '*' && dis[ni][nj] == inf) {
			cnt += cnt_tmp;
			DFS1(ni, nj);
		}
	}
}
void DFS2(int x, int y) {
	vis[x][y] = true;
	dis[x][y] = view;
	for (int i = 0; i < 4; ++i) {
		int ni = x + dx[i];
		int nj = y + dy[i];
		if (ni < 0 || ni > n || nj < 0 || nj > m) continue;
		if (grid[ni][nj] != '*' && !vis[x][y]) {
			DFS2(ni, nj);
		}
	}
}
void DFS_init() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] != '*' && dis[i][j] == inf) {
				cnt = 0;
				dis[i][j] = 0;
				DFS1(i, j);
				view = cnt;
				if (!vis[i][j]) DFS2(i, j);
			}
		}
	}
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> grid[i][j];
		}	
	}
	init();
	DFS_init();
	while (k--) {
		int posx, posy; cin >> posx >> posy;
		--posx; --posy;
		cout << dis[posx][posy] << "\n";
	}
	return 0;
}
