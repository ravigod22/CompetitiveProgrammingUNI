#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<string> names;
	vector<bool> no_repe(n, false);
	map<int,vector<tuple<int,int,int>>> pos;
	int table[n + 1][6][6];
	bool vis[n + 1][6][6];
	memset(vis, false, sizeof(vis));
	for (int i = 0; i < n; ++i) {
		string person;
		cin >> person;
		names.push_back(person);
		
		for (int j = 0; j < 5; ++j) {
			for (int k = 0; k < 5; ++k) {
				cin >> table[i][j][k];
				int x = table[i][j][k];
				pos[x].push_back({i, j, k}); 
			}
		}
	}
	int m;
	cin >> m;
	vector<int> numbers(m);
	vector<string> winners;
	for (int a = 0; a < m; ++a) {
		cin >> numbers[a];
		for(auto e : pos[numbers[a]]) {
			int ind = get<0>(e);
			int x = get<1>(e);
			int y = get<2>(e);
			vis[ind][x][y] = true;
		}
		for (int i = 0; i < n; ++i) {
			bool ans = false;
			if (no_repe[i]) continue;
			for (int j = 0; j < 5; ++j) {
				int cnt = 0;
				for (int k = 0; k < 5; ++k) {
					if (vis[i][j][k]) ++cnt;
				}
				if (cnt == 5) {
					ans = true;
					break;
				}
			}
			if (!ans) {
				for (int j = 0; j < 5; ++j) {
					int cnt = 0;
					for (int k = 0; k < 5; ++k) {
						if (vis[i][k][j]) ++cnt;
					}
					if (cnt == 5) {
						ans = true;
						break;
					}
				}	
			}
			if (!ans) {
				int cnt_diago = 0;
				for (int j = 0; j < 5; ++j) {
					if (vis[i][j][j]) ++cnt_diago;
				}
				if (cnt_diago == 5) {
					ans = true;
				}
			}
			if (!ans) {
				int cnt_antidiago = 0;
				for (int j = 0; j < 5; ++j) {
					if(vis[i][j][4 - j]) ++cnt_antidiago;
				}
				if (cnt_antidiago == 5) {
					ans = true;
				}
			}
			if (ans) {
				winners.push_back(names[i]);
				no_repe[i] = true;
			}
		}
	}
	int rpta = winners.size();
	cout << rpta << '\n';
	for (int i = 0; i < rpta; ++i) {
		cout << winners[i] << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin >> test;
	while (test--) {
		solve();
	}
	return 0;
}
