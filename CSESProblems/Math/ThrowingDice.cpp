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
            M[i][i] = 1;
    }
    void dbg() {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cout << M[i][j] << " \n"[j + 1 == n];
    }
    Matrix operator + (const Matrix &other) {
        Matrix R(n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                R.M[i][j] = (M[i][j] + other.M[i][j]) % mod;
        return R;
    }
    Matrix operator * (const Matrix &other) {
        Matrix R(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    R.M[i][j] = (R.M[i][j] + (1LL * M[i][k] * other.M[k][j]) % mod) % mod;
                }
            }
        }
        return R;
    }
    friend Matrix binpow(Matrix& A, long long e) {
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

int F(Matrix A, vector<int> base) {
    int ans = 0;
    for (int i = 0; i < 6; ++i) {
        ans = (ans + (1LL * base[5 - i] * A.M[0][i]) % mod) % mod;
    }
    return ans;
}

int main() {
    long long k;
    cin >> k;
    Matrix A(6);
    vector<int> base(6);
    base[0] = 1;
    for (int i = 1; i < 6; ++i)
        for (int j = 0; j < i; ++j)
            base[i] += base[j];
    if (k < 6) {
        cout << base[k] << "\n";
        return 0;
    }
    for (int i = 0; i < 6; ++i)
        A.M[0][i] = 1;
    for (int i = 1; i < 6; ++i) {
        A.M[i][i - 1] = 1;
    }
    Matrix R = binpow(A, k - 5);
    int res = F(R, base);
    cout << res << "\n";
    return 0;
}
