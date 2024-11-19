#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int a[maxn];

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int piglet = 0;
    for (int i = 0; i < n; ++i) {
        int tmp = a[i];
        int cnt = 0;
        while (k <= tmp && cnt < 3) {
            tmp -= k;
            cnt++;
        } 
        piglet += tmp;
    }
    cout << piglet;
    return 0;
}
