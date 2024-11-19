#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt;
	while (tt--) {
        int n; cin >> n;
		string s; cin >> s;
        // N : 0, S : 1, E : 2, W : 3
        if (n == 1) {
            cout << "NO\n";
            continue;
        }
        int times[4];
        memset(times, 0, sizeof(times));
        int posX = 0, posY = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'N') times[0]++; posY++;
            if (s[i] == 'S') times[1]++; posY--;
            if (s[i] == 'E') times[2]++; posX++;
            if (s[i] == 'W') times[3]++; posX--;
        }
        if ((times[0] + times[1]) & 1 || (times[2] + times[3]) & 1) {
            cout << "NO" << "\n";
            continue;
        }
        if ((times[0] < 2 && times[1] < 2) && (times[2] < 1 && times[3] < 1)) {
            cout << "NO" << "\n";
            continue;
        }
        if ((times[0] < 1 && times[1] < 1) && (times[2] < 2 && times[3] < 2)) {
            cout << "NO" << "\n";
            continue;
        }
        // N > S
        int tmpY = (times[0] + times[1]) / 2;
        int tmpX = (times[2] + times[3]) / 2;
        if (times[0] > times[1]) {
            int cnt = times[0] - tmpY;
            for (int i = 0; i < n; ++i) {
                if (s[i] == 'N' && cnt-- > 0)
                    s[i] = 'S';
            }
        } 
        else if (times[0] < times[1]) {
            int cnt = times[1] - tmpY;
            for (int i = 0; i < n; ++i) {
                if (s[i] == 'S' && cnt-- > 0)
                    s[i] = 'N';
            }
        }
        // E > W
        if (times[2] > times[3]) {
            int cnt = times[2] - tmpX;
            for (int i = 0; i < n; ++i) {
                if (s[i] == 'E' && cnt-- > 0) s[i] = 'W';
            }
        }
        else if (times[2] < times[3]) {
            int cnt = times[3] - tmpX;
            for (int i = 0; i < n; ++i) {
                if (s[i] == 'W' && cnt-- > 0) s[i] = 'E';
            }
        }
        vector<char> ans(n, 'T');
        int cnt_Y = tmpY / 2;
        int cnt_X = tmpX / 2;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'S' && cnt_Y--) {
                ans[i] = 'H';
            }
            if (s[i] == 'W' && cnt_X--) {
                ans[i] = 'H';
            }
        }
        cnt_Y = tmpY / 2;
        cnt_X = tmpX / 2;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'N' && cnt_Y--) {
                ans[i] = 'H';
            }
            if (s[i] == 'E' && cnt_X--) {
                ans[i] = 'H';
            }
        }
        for (int i = 0; i < n; ++i) {
            if (ans[i] == 'T') ans[i] = 'R';
        }
        for (auto e : ans) {
            cout << e;
        }
        cout << "\n";
	}
	return 0;
}
