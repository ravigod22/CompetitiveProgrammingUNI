#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

struct Matrix {
    int n, neutro;
    vector<vector<int>> M;
    Matrix(int _n, int _neutro = 0) : n(_n), neutro(_neutro) {
        M.resize(n, vector<int> (n, neutro));
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
                if (C.M[i][j] > mod) C.M[i][j] -= mod;
            }
        }
        return C;
    }
    Matrix operator * (const Matrix& other) {
        Matrix C(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    C.M[i][j] = (C.M[i][j] + (1LL * M[i][k] * other.M[k][j]) % mod) % mod;
                }
            }
        }
        return C;
    }
    friend Matrix binpow (Matrix A, int e) {
        Matrix R(A.n);
        R.I();
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
        int u, v;
        cin >> u >> v;
        u--, v--;
        A.M[u][v] += 1;
    }
    Matrix R = binpow(A, k);
    cout << R.M[0][n - 1] << "\n";
    return 0;
}
