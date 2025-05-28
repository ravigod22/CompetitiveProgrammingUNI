#include <bits/stdc++.h>
using namespace std;

const int maxn = (1 << 11) + 5;
int id[maxn][maxn];
char grid[maxn][maxn];
char abe[26];
int cnt = 0;
int n, x, y;

struct State {
    int x0, y0, x1, y1, x2, y2, x3, y3;
};

void solve_iterative(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {
    stack<State> st;
    st.push({x0, y0, x1, y1, x2, y2, x3, y3});

    while (!st.empty()) {
        State cur = st.top();
        st.pop();

        int dis = cur.x1 - cur.x0 + 1;
        if (dis == 2) {
            if (cur.x0 == x && cur.y0 == y) {
                id[cur.x1][cur.y1] = id[cur.x2][cur.y2] = id[cur.x3][cur.y3] = cnt++;
            } else if (cur.x1 == x && cur.y1 == y) {
                id[cur.x0][cur.y0] = id[cur.x2][cur.y2] = id[cur.x3][cur.y3] = cnt++;
            } else if (cur.x2 == x && cur.y2 == y) {
                id[cur.x0][cur.y0] = id[cur.x1][cur.y1] = id[cur.x3][cur.y3] = cnt++;
            } else if (cur.x3 == x && cur.y3 == y) {
                id[cur.x0][cur.y0] = id[cur.x1][cur.y1] = id[cur.x2][cur.y2] = cnt++;
            }
            continue;
        }

        int c1 = cur.x0 + dis / 2 - 1, c2 = cur.y0 + dis / 2 - 1;
        if ((c1 == x && c2 == y) || (c1 + 1 == x && c2 == y) || (c1 + 1 == x && c2 + 1 == y) || (c1 == x && c2 + 1 == y)) {
            int newdis = dis / 4;
            st.push({cur.x0 + newdis, cur.y0 + newdis, cur.x1 + newdis, cur.y1 - newdis, cur.x2 - newdis, cur.y2 + newdis, cur.x3 - newdis, cur.y3 - newdis});
        } else {
            if (x <= c1 && y <= c2) {
                st.push({cur.x0, cur.y0, cur.x0, cur.y0 + dis / 2 - 1, cur.x0 + dis / 2 - 1, cur.y0, cur.x0 + dis / 2 - 1, cur.y0 + dis / 2 - 1});
            } else if (x <= c1 && y <= cur.y1) {
                st.push({cur.x1, cur.y1 - dis / 2 + 1, cur.x1, cur.y1, cur.x1 + dis / 2 - 1, cur.y1 - dis / 2 + 1, cur.x1 + dis / 2 - 1, cur.y1});
            } else if (x <= cur.x2 && y <= c2) {
                st.push({cur.x2 - dis / 2 + 1, cur.y2, cur.x2 - dis / 2 + 1, cur.y2 + dis / 2 - 1, cur.x2, cur.y2, cur.x2, cur.y2 + dis / 2 - 1});
            } else if (x <= cur.x3 && y <= cur.y3) {
                st.push({cur.x3 - dis / 2 + 1, cur.y3 - dis / 2 + 1, cur.x3 - dis / 2 + 1, cur.y3, cur.x3, cur.y3 - dis / 2 + 1, cur.x3, cur.y3});
            }
        }
    }
}

int main() {
    cin >> n >> x >> y;
    id[x][y] = 1e9;
    grid[x][y] = '.';
    for (int i = 0; i < 26; ++i) {
        abe[i] = char(i + 'a');
    }
    solve_iterative(1 , 1, 1, n, n , 1, n , n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << id[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

