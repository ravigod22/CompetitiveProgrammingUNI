#include <iostream>
#include <vector>
using namespace std;

int maxKForAlice(int n, vector<int>& a) {
    int max_k = 0;
    int curr_max = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] > curr_max) {
            max_k = max(max_k, curr_max);
            curr_max = a[i];
        } else {
            max_k = max(max_k, a[i]);
        }
    }
    return max_k;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int max_k = maxKForAlice(n, a);
        cout << max_k << endl;
    }
    return 0;
}

