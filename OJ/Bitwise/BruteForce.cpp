#include <bits/stdc++.h>
using namespace std;
const long long E = (1LL << 40);
const int maxn = 5e8;

clock_t startTime;

double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long myRand(long long b) {
	return (unsigned long long)rng() % b;
}


pair<long long, long long> solve1(int n, vector<long long>& v) {
    long long resXor = 0;
    long long resOr = 0;
    for (int b = 0; b < 41; ++b) {
        long long mod = 1LL << b;
        vector<pair<long long, int>> aux;
        for (int i = 0; i < n; ++i) {
            if (v[i] & mod) aux.emplace_back(v[i] % mod, 1);
            else aux.emplace_back(v[i] % mod, 0);
        }
        sort(aux.begin(), aux.end());
        vector<long long> one, zero;
        int ansXor = 0;
        int ansOr = 0;
        for (int i = 0; i < n; ++i) {
            long long target = mod - aux[i].first;
            if (aux[i].second == 1) {
                one.emplace_back(aux[i].first);
                int nones = 0, nzeros = zero.size();
                auto n1 = lower_bound(one.begin(), one.end(), target);
                if (n1 != one.end()) nones = (int)one.size() - (n1 - one.begin());
                auto n0 = lower_bound(zero.begin(), zero.end(), target);
                if (n0 != zero.end()) nzeros = n0 - zero.begin();
                if (0 < nones || 0 < nzeros) ansOr |= 1;
                nones %= 2;
                nzeros %= 2;
                ansXor ^= (nones ^ nzeros);
            }
            else {
                zero.emplace_back(aux[i].first);
                int nones = one.size(), nzeros = 0; 
                auto n1 = lower_bound(one.begin(), one.end(), target);
                if (n1 != one.end()) nones = n1 - one.begin();
                auto n0 = lower_bound(zero.begin(), zero.end(), target);
                if (n0 != zero.end()) nzeros = (int)zero.size() - (n0 - zero.begin());
                if (0 < nzeros || 0 < nones) ansOr |= 1;
                nones %= 2;
                nzeros %= 2;
                ansXor ^= (nones ^ nzeros);
            }
        }
        if (ansXor) resXor |= mod;
        if (ansOr) resOr |= mod;
    }
    return {resXor, resOr};
}

pair<long long, long long> solve(int n, vector<long long>& v) {
    long long resXor = 0;
    long long resOr = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            resXor ^= (v[i] + v[j]);
            resOr |= (v[i] + v[j]);
        }
    }
    return {resXor, resOr};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);
    // while (true) {
        const int n = 1e5;
        vector<long long> v(n);
        for (auto& e : v) e = myRand(E);
    startTime = clock();
        auto res = solve1(n, v);
    //}
    double endTime = getCurrentTime();
    cout << endTime << "\n";
    return 0;
}
