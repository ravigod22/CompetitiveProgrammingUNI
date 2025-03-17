#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[5];
    for (int i = 0; i < 5; ++i) cin >> a[i];
    for (int i = 1; i < 5; ++i) {
        bool can = true;
        swap(a[i], a[i - 1]);
        for (int j = 1; j < 5; ++j) {
            if (a[j - 1] >= a[j]) can = false;
        }
        if (can) {
            cout << "Yes\n";
            return 0;
        }
        swap(a[i], a[i - 1]);
    }
    cout << "No\n";
    return 0;
}
