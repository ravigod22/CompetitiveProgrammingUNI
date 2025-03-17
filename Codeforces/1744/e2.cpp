#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 gcd(i64 a, i64 b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        i64 a, b, c, d; cin >> a >> b >> c >> d;
        i64 tmp = a * b;
        i64 ans = 1;
        vector<i64> A, B, divi;
        for (int i = 1; 1LL * i * i <= a; ++i) {
            if (a % i == 0) {
                A.emplace_back(i);
                if (a / i != i) A.emplace_back(a / i);
            }
        }
        for (int i = 1; 1LL * i * i <= b; ++i) {
            if (b % i == 0) {
                B.emplace_back(i);
                if (b / i != i) B.emplace_back(b / i);
            }
        }
        for (i64 e1 : A) {
            for (i64 e2 : B) {
                divi.emplace_back(e1 * e2);
            }
        }
        bool find = false;
        for (i64 e : divi) {
            i64 L = (a + e) / e;
            i64 R = c / e;
            if (L <= R) {
                i64 aux = tmp / e;
                i64 L1 = (b + aux) / aux;
                i64 R1 =  d / aux;
                if (L1 <= R1) {
                    find = true;
                    cout << L * e << " " << L1 * aux << "\n";
                    ans = L * e * L1 * aux;
                    break;
                }
            }
        }
        if (find) {
            assert(ans % tmp == 0);
            continue;
        }
        cout << -1 << " " << -1 << "\n";
    }
    return 0;
}


