#include <bits/stdc++.h>
using namespace std;

multiset<int> L;
multiset<int> R;

void add(int e) {
    if (L.empty()) {
        L.insert(e);
    }
    else {
        int mnright = *R.begin();
        if (L.size() == R.size()) {
            if (e > mnright) {
                L.insert(mnright);
                R.extract(mnright);
                R.insert(e);
            }
            else {
                L.insert(e);
            }
        }
        else if (L.size() == R.size() + 1) {
            R.insert(e);    
        }
    }
}
void del(int e) {
    if (!L.count(e) && !R.count(e)) return;
    if (L.size() == R.size()) {
        if (R.count(e)) {
            R.extract(e);
        }
        else {
            int mn = *R.begin();
            L.extract(e);
            R.extract(mn);
            L.insert(mn);
        }
    }
    else if (L.size() == R.size() + 1) {
        if (L.count(e)) {
            L.extract(e);
        }
        else {
            int mx = *(--L.end());
            R.extract(e);
            L.extract(mx);
            R.insert(mx);
        }
    }
}

void query() {
    if (L.empty()) {
        cout << "Empty!\n";
    } 
    else {
        int len = L.size() + R.size();
        if (len & 1) {
            cout << *(--L.end()) << "\n";
        }
        else {
            int a = *(--L.end());
            int b = *(R.begin());
            cout << (a + b) / 2 << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            add(x);
        }
        else if (op == 2) {
            int x;
            cin >> x;
            del(x);
        }
        else {
            query();
        }
    }
    return 0;
}
