#include <bits/stdc++.h>
using namespace std;

const int maxn = (1 << 11) + 5;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};
char grid[maxn][maxn];
int n, x, y;
char build(int x0, int y0, int x1, int y1, int x2, int y2) {
    char ans;
    vector<int> exist(26, false);
    for (int i = 0; i < 4; ++i) {
        int newi = x0 + dx[i], newj = y0 + dy[i];
        if (newi <= 0 || newj <= 0 || newi > n || newj > n) continue;    
        if (grid[newi][newj] >= 'A' && grid[newi][newj] <= 'Z') exist[grid[newi][newj] - 'A'] = 1;
    }
    for (int i = 0; i < 4; ++i) {
        int newi = x1 + dx[i], newj = y1 + dy[i];
        if (newi <= 0 || newj <= 0 || newi > n || newj > n) continue;    
        if (grid[newi][newj] >= 'A' && grid[newi][newj] <= 'Z') exist[grid[newi][newj] - 'A'] = 1;
    }
    for (int i = 0; i < 4; ++i) {
        int newi = x2 + dx[i], newj = y2 + dy[i];
        if (newi <= 0 || newj <= 0 || newi > n || newj > n) continue;    
        if (grid[newi][newj] >= 'A' && grid[newi][newj] <= 'Z') exist[grid[newi][newj] - 'A'] = 1;
    }
    for (int i = 0; i < 26; ++i) {
        if (exist[i]) continue;
        ans = char(i + 'A');
        break;
    }
    return ans;
}

void fill_grid(int x2, int y2, int side) {
    int dis = 2;
    if (side == 0) {
        int x0 = x2 - dis + 1, y0 = y2;
        int x1 = x2, y1 = y2 + dis - 1;
        char tmp = build(x0, y0, x1, y1, x2, y2);
        grid[x0][y0] = grid[x1][y1] = grid[x2][y2] = tmp;
    }
    else if (side == 1) {
        int x0 = x2, y0 = y2 + dis - 1;
        int x1 = x2 + dis - 1, y1 = y2;
        char tmp = build(x0, y0, x1, y1, x2, y2);
        grid[x0][y0] = grid[x1][y1] = grid[x2][y2] = tmp;
    }
    else if (side == 2) {
        int x0 = x2, y0 = y2 - dis + 1;
        int x1 = x2 + dis - 1, y1 = y2;
        char tmp = build(x0, y0, x1, y1, x2, y2);
        grid[x0][y0] = grid[x1][y1] = grid[x2][y2] = tmp;
    }
    else if (side == 3) {
        int x0 = x2 - dis + 1, y0 = y2;
        int x1 = x2, y1 = y2 - dis + 1;
        char tmp = build(x0, y0, x1, y1, x2, y2);
        grid[x0][y0] = grid[x1][y1] = grid[x2][y2] = tmp;
    }
}


void build_L(int x2, int y2, int side, int len) {
    int dis = len;
    if (side == 0) {
        int x0 = x2 - dis + 1, y0 = y2;
        int x1 = x2, y1 = y2 + dis - 1;
        int newx = x2 - dis / 4, newy = y2 + dis / 4;
        if (len == 2) {
            return fill_grid(x2, y2, side);
        }
        if (len == 4) {
            fill_grid(x0, y0, 1);
            fill_grid(x2, y2, 0);
            fill_grid(x1, y1, 3);
            fill_grid(newx, newy, 0);
            return;
        }
        build_L(x0, y0, 1, len / 2);
        build_L(x2, y2, 0, len / 2);
        build_L(x1, y1, 3, len / 2);
        build_L(newx, newy, 0, len / 2);
    }
    else if (side == 1) {
        int x0 = x2, y0 = y2 + dis - 1;
        int x1 = x2 + dis - 1, y1 = y2;
        int newx = x2 + dis / 4, newy = y2 + dis / 4;
        if (len == 2) {
            return fill_grid(x2, y2, side);
        }
        if (len == 4) {
            fill_grid(x0, y0, 2);
            fill_grid(x1, y1, 0);
            fill_grid(x2, y2, 1);
            fill_grid(newx, newy, 1);
        }
        build_L(x2, y2, 1, len / 2);
        build_L(x0, y0, 2, len / 2);
        build_L(x1, y1, 0, len / 2);
        build_L(newx, newy, 1, len / 2);
    }
    else if (side == 2) {
        int x0 = x2, y0 = y2 - dis + 1;
        int x1 = x2 + dis - 1, y1 = y2;
        int newx = x2 + dis / 4, newy = y2 - dis / 4;
        if (len == 2) {
            return fill_grid(x2, y2, side);
        }
        if (len == 4) {
            fill_grid(x0, y0, 1);
            fill_grid(x1, y1, 3);
            fill_grid(x2, y2, 2);
            fill_grid(newx, newy, 2);
            return;
        }
        build_L(x2, y2, 2, len / 2);
        build_L(x0, y0, 1, len / 2);
        build_L(x1, y1, 3, len / 2);
        build_L(newx, newy, 2, len / 2);
    }
    else if (side == 3) {
        int x0 = x2 - dis + 1, y0 = y2;
        int x1 = x2, y1 = y2 - dis + 1;
        int newx = x2 - dis / 4, newy = y2 - dis / 4;
        if (len == 2) {
            return fill_grid(x2, y2, side);
        }
        if (len == 4) {
            fill_grid(x0, y0, 2);
            fill_grid(x1, y1, 0);
            fill_grid(x2, y2, 3);
            fill_grid(newx, newy, 3);
            return;
        }
        build_L(x0, y0, 2, len / 2);
        build_L(x1, y1, 0, len / 2);
        build_L(x2, y2, 3, len / 2);
        build_L(newx, newy, 3, len / 2);
    }
}

void solve(int x0, int y0, int n) {
    int dis = n;
    int x1 = x0, y1 = y0 + dis - 1;
    int x2 = x0 + dis - 1, y2 = y0;
    int x3 = x0 + dis - 1, y3 = y0 + dis - 1;
    if (n == 2) {
        if (x0 == x && y0 == y) {
            char tmp = build(x1, y1, x2, y2, x3, y3);
            grid[x1][y1] = grid[x2][y2] = grid[x3][y3] = tmp;
            return;
        }
        else if (x1 == x && y1 == y) {
            char tmp = build(x0, y0, x2, y2, x3, y3);
            grid[x0][y0] = grid[x2][y2] = grid[x3][y3] = tmp;
            return;
        }
        else if (x2 == x && y2 == y) {
            char tmp = build(x0, y0, x1, y1, x3, y3); 
            grid[x0][y0] = grid[x1][y1] = grid[x3][y3] = tmp;
            return;
        }
        else if (x3 == x && y3 == y) {
            char tmp = build(x0, y0, x1, y1, x2, y2);
            grid[x0][y0] = grid[x1][y1] = grid[x2][y2] = tmp;
            return;
        }
    }
    // is the pixel in the center?
    int c1 = x0 + dis / 2 - 1, c2 = y0 + dis / 2 - 1;
    if ((c1 == x && c2 == y) || (c1 + 1 == x && c2 == y) || (c1 + 1 == x && c2 + 1 == y) || (c1 == x && c2 + 1 == y)) {
        int newdis = dis / 4;
        build_L(x0, y0, 1, dis / 2);
        build_L(x1, y1, 2, dis / 2);
        build_L(x2, y2, 0, dis / 2);
        build_L(x3, y3, 3, dis / 2);
        solve(x0 + newdis, y0 + newdis, dis / 2);
    }
    else {
        if (x <= c1 && y <= c2) {
            solve(x0, y0, dis / 2);
            build_L(x3, y3, 3, dis);
        }
        else if (x <= c1 && y <= y1) {
            // C 2
            solve(x0, y0 + dis / 2, dis / 2);
            build_L(x2, y2, 0, dis);
        }
        else if (x <= x2 && y <= c2) {
            // C 3
            solve(x0 + dis / 2, y0, dis / 2);
            build_L(x1, y1, 2, dis);
        }
        else if (x <= x3 && y <= y3) {
            // C 4
            solve(x0 + dis / 2, y0 + dis / 2, dis / 2);
            build_L(x0, y0, 1, dis);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x >> y;
    if (n == 1) {
        cout << ".\n";
        return 0;
    }
    solve(1 , 1, n);
    grid[x][y] = '.';
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
    return 0;
}
