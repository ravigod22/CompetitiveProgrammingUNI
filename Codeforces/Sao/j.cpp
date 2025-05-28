#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = (119 << 23) + 1, root = 62;
int N, M;

ll modpow(ll a, ll e) {
    ll res = 1;
    while (e) {
        if (e & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        e /= 2;
    }
    return res; 
}

void ntt(vector<ll> &a) {
    int n = a.size(), L = 31 - __builtin_clz(n);
    static vector<ll> rt(2, 1);
    for (static int k = 2, s = 2; k < n; k *= 2, s++) {
        rt.resize(n);
        ll z[] = {1, modpow(root, mod >> s)};
        for (int i = k; i < 2 * k; ++i) {
            rt[i] = rt[i / 2] * z[i & 1] % mod;
        }
    }
    vector<ll> rev(n);
    for (int i = 0; i < n; ++i)
        rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    for (int i = 0; i < n; ++i) {
        if (i < rev[i]) {
            swap(a[i], a[rev[i]]);
        }
    }
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; ++j) {
                ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
                a[i + j + k] = ai - z + (z > ai ? mod : 0);
                ai += (ai + z >= mod ? z - mod : z);
            }
        }
    }
}


vector<ll> conv(vector<ll> a, vector<ll> b) {
    if (a.empty() || b.empty()) return {};
    int s = a.size() + b.size() - 1, B = 32 - __builtin_clz(s), n = 1 << B;
    int inv = modpow(n, mod - 2);
    vector<ll> L(a), R(b), out(n);
    L.resize(n), R.resize(n);
    ntt(L), ntt(R);
    for (int i = 0; i < n; ++i) {
        out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
    }
    ntt(out);
    return {out.begin(), out.begin() + s};
}

vector<ll> add(vector<ll>& A, vector<ll>& B) {
    const int n = max(A.size(), B.size());
    vector<ll> C(n, 0);
    for (int i = 0, p = 0, q = 0; i < n; ++i, p++, q++) {
        if (p < A.size()) C[i] = (C[i] + A[p]) % mod;
        if (q < B.size()) C[i] = (C[i] + B[q]) % mod;
    }
    return C;
}

void escalar(vector<ll> &A, ll e) {
    const int n = A.size();
    for (int i = 0; i < n; ++i) {
        A[i] = (A[i] * e) % mod;
    }
}


vector<ll> binpow(vector<ll> A, ll e) {
    vector<ll> ans = {1};
    while (e) {
        if (e & 1) ans = conv(ans, A);
        A = conv(A, A);
        e /= 2;
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    vector<ll> P(N + 1);
    for (int i = 0; i <= N; ++i) {
        cin >> P[i];
    }
    cin >> M;
    vector<ll> Q(M + 1);
    for (int j = 0; j <= M; ++j) {
        cin >> Q[j];
    }
    int L = N * M + 1;
    vector<ll> res(L, 0);
    vector<ll> tmp = {1};
    for (int i = 0; i <= N; ++i) {
        vector<ll> ans = tmp;
        escalar(ans, P[i]);
        res = add(res, ans);
        if (i < N) tmp = conv(tmp, Q);
    }
    for (int i = 0; i <= N * M; ++i) {
        cout << res[i] << " \n"[i == N * M]; 
    }
    return 0;
}
