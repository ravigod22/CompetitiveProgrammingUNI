#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<vector<int>> a(3, vector<int> (n));
        long long sum = 0;
        for (int i = 0; i < 3; ++i) {
            long long tmp = 0;
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
                tmp += a[i][j];
            }
            sum = tmp;
        }
        long long tot = (sum + 2) / 3;
        vector<vector<long long>> prefix(3, vector<long long> (n + 1, 0));
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n; ++j) {
                prefix[i][j + 1] = prefix[i][j] + 0ll + a[i][j];
            }
        }
        bool can = false;
        vector<int> init(3);
        iota(init.begin(), init.end(), 1);
        do {
            int A = init[0] - 1;
            int B = init[1] - 1;
            int C = init[2] - 1;
            bool could = true;
            int posA, posB, posC;
            vector<pair<int, int>> result(3);
            //cout << "=====================================\n";
            for (int i = 1; i <= n; ) {
                while (prefix[A][i] < tot && i <= n) {
                    ++i;
                }
                posA = i;
                //cout << A <<" "<< posA << "\n";
                result[A] = {1, i};
                int next = min(i + 1, n);
                i = next;
                if (next == n) {
                    could = false;
                    break;
                }
                while (prefix[B][i] - prefix[B][posA] < tot && i <= n) {
                    ++i;
                }
                posB = i;
                //cout << B << " " << posB << "\n";
                result[B] = {posA + 1, i};
                if (i == n + 1) {
                    could = false;
                    break;
                }
                if (prefix[C][n] - prefix[C][posB] >= tot) {
                    result[C] = {posB + 1, n};
                }
                else could = false;
                break;
            }
            if (could) {
                can = true;
                for (int i = 0; i < 3; ++i) {
                    cout << result[i].first << " " << result[i].second << " ";
                }
                cout << "\n";
                break;
            }
        } while (next_permutation(init.begin(), init.end()));
        if (!can) cout << "-1\n";
    }
    return 0;
}

