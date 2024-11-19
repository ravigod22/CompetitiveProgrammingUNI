#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;

const int INF = 2e9 + 5;
const int N = 100 + 5;

int dis[N][N];
int G[N][N];
bool take[N][N];

int main() {
    fast_io;
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    a--; b--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) dis[i][j] = 0;
            else dis[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        u--; v--;
        dis[v][u] = min(dis[v][u], w);
        dis[u][v] = min(dis[u][v], w);
        G[u][v] = G[v][u] = w;
    }

     // Floyd Warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++){
                int d = dis[i][k] + dis[k][j];
                if (dis[i][k] == INF or dis[k][j] == INF) continue;
                if (d < dis[i][j]) {
                    dis[i][j] = d;
                }
            }
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dis[a][i] + G[i][j] + dis[j][b] == dis[a][b]) {
                take[i][j] = take[j][i] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (take[i][j]) continue;
            ans += G[i][j];
        }
    }
    cout << ans << "\n";
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }*/
  
    return 0;
}
