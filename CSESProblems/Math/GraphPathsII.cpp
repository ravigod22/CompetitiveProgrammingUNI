#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 inf = 2e18;

struct Matrix {
    int n;
    i64 neutro;
    vector<vector<i64>> M;
    Matrix(int _n, i64 _neutro = inf) : n(_n), neutro(_neutro) {
        M.resize(n, vector<i64> (n, neutro));
    }
    void I() {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                M[i][j] = (i == j);
    }
    Matrix operator + (const Matrix& other) {
        Matrix C(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                C.M[i][j] = M[i][j] + other.M[i][j];
            }
        }
        return C;
    }
    Matrix operator * (const Matrix& other) {
        Matrix C(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    C.M[i][j] = min(C.M[i][j], M[i][k] + other.M[k][j]);
                }
            }
        }
        return C;
    }
    friend Matrix binpow (Matrix A, int e) {
        Matrix R = A;
        e--;
        while (e) {
            if (e & 1) R = R * A;
            A = A * A;
            e /= 2;
        }
        return R;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    Matrix A(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        A.M[u][v] = min(A.M[u][v], 1LL * w);
    }
    Matrix R = binpow(A, k);
    i64 ans = R.M[0][n - 1];
    if (ans == inf) ans = -1;
    cout << ans << "\n";
    return 0;
}

