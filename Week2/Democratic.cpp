#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 5;
int n, m;
char city[N][N];

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> city[i][j]; 
		}
	}
    string result;
	for (int i = 0; i < m; ++i) {
		vector<int> cnt(27, 0);
		for (int j = 0; j < n; ++j) {
			cnt[city[j][i] - 'a']++;
		}
		int x = *max_element(cnt.begin(), cnt.end());
		int min_e = 2e9;
		for (int j = 0; j < 27; ++j) {
			if (cnt[j] == x) {
				min_e = min(min_e, j);
			}
		}
		char tmp = min_e + 'a';
	    result += tmp;
	}
    cout << result << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1;
	//cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}
