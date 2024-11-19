#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        vector<int> ingre(8);
        for (int& e : ingre) cin >> e;
        if (ingre[0] == -1) break;
        int ans = 0;
        for (int i = 0; i < 4; ++i) {
            int tmp = (ingre[i] + ingre[i + 4] - 1) / ingre[i + 4];
            ans = max(ans, tmp);
        }
        for (int i = 0; i < 4; ++i) {
            int tmp = ans * ingre[i + 4] - ingre[i];
            cout << tmp << " \n"[i == 3];
        }
    }
    return 0;
}
